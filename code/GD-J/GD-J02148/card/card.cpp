#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],v=0;
int o[500005],oo=0;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a[n+1]=m+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	a[0]=a[1];
	for(int i=1;i<=n+1;i++){
		
		if(a[i]!=a[i-1]){
			o[++oo]=i-1;
			v=1;
		}
		if(a[i]==a[i-1]){
			v++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<o[i]<<" ";
	}
	/*
	for(int ti=1;ti<=n;ti++){
		for(int i=1;i<=n;i++){
			o[i]=0;
		}
		int now=ti;
		for(int i=ti;i<=n;i++){
			if(o[a[i]]){
				now=o[i];
				for(int j=now+1;j<=n;j++){
					if(a[j]!=a[i]){
						o[a[j]]=0;
					}
					
				}
			}
			else{
				o[a[i]]=now;
			}
			now++;
		}
		for(int i=1;i<=m;i++){
			if(!o[i]){
				v[i]++;
			}
			
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v[i]<<" ";
	}*/
	return 0;
}
