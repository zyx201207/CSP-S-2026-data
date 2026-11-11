#include <bits/stdc++.h>
using namespace std;
int N=2e5+5;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m;
	cin>>n>>m;
	if (n==1){
		cout <<1;
		return 0;
	}
	int cr[N];
	for (int i=1;i<=n;i++){
		cin>>cr[i];
	}
	sort (cr+1,cr+n);
	int pre[N];
	int ans=1;
	for (int i=1;i<=n;i++){
		pre[i]=0;
	}
	for (int i=n-1;i>=1;i--){
		int a=cr[i+1]-cr[i];
		pre[i]=pre[i+1]+a;
		//cout <<pre[i]<<" ";
	}
	//cout <<endl;
	for (int i=n;i>=1;i--){
		int da=1;
		int ti=m;
		for (int j=1;j<i;j++){
			int c=pre[i-j]-pre[i];
			//cout << c<<" "<<endl;
			if(c<=ti){
				ti-=c;
				da++;
			
			}
			
		}
		ans=max(ans,da);
		if (i<=ans){
			break;
		}
	}
	cout <<ans;
	return 0;
}
