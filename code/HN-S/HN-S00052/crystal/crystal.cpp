#include<bits/stdc++.h>
using namespace std;
int n,flag,maxx=1;
long long m,a[500005],d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i){
		if(a[i]==a[i+1]){
			flag=1;
		}
		else {
			flag=0;
		}
	}
	if(flag==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;++i){
		int max1=1;
		d=m;
		for(int j=i-1;j>=1;j--){
			if(d>0){
				if(d>=a[i]-a[j]){
					d=d-(a[i]-a[j]);
					max1++;
				}
			}
			else{
				break;
			}
		}
		maxx=max(max1,maxx);
	}
	cout<<maxx;
	return 0;
}
