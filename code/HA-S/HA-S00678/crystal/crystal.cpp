#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxx=0,c,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		c=m;ans=-1;
		for(int j=1;j<=n;j++){
			if(a[i]<a[j]){
				continue;
			}else{
				c-=a[i]-a[j];
				ans=i;
			}
			if(c==0||c>0){	
				if(maxx<ans){
					maxx=ans;
				}
			}
		}
	}
	cout<<maxx;
	return 0;
}
