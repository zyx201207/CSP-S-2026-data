#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],k,w,max1=-1;
int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystsl.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int v=0;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]==a[i-1]-a[i-2]){
			v=1;
			k=a[i]-a[i-1];
		}
		else{
			v=0;
			break;
		}
	}
	if(v){
		for(int i=n;i>=1;i--){
			if(k*i*(i-1)/2<=m){
				cout<<i;
				return 0;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			int sum=0;
			w=0;
			for(int j=i;j>=1;j--){
				sum=sum+(a[i]-a[j]);
				if(sum>m){
					break;
				}
				w++;
			}
			max1=max(max1,w);
		}
		cout<<max1;
	}
	return 0;
}
