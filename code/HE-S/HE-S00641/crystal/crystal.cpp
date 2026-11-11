#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<5000){
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			int num=0;
			for(int j=i-1;j>=1;j--){
				num+=a[i]-a[j];
			}
			if(num<=m){
				cout<<i<<endl;
				break;
			}
		}
	}
	else{
		int num=0,c=a[2]-a[1];
		for(int i=1;i<=n;i++){
			num+=c*i;
			if(num>m){
				cout<<i;
				break;
			}
		}
	}
	return 0;
} 
