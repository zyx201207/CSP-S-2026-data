#include <bits/stdc++.h>
using namespace std;
int n,m,a[200000],maxn=-1,ans=1,maxnn=-1,anss=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=maxn)
			maxn=a[i];
		ans=ans&a[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
		
	if(m==n){
		cout<<ans;
		return 0;
	}
		
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=a[i]&a[j];
				if(maxnn<=x)
					maxnn=x;
			}
		}
		cout<<maxnn;
		return 0;
	}
	else
		cout<<1;
	
}
		
