#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],v[500005],t=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(t<=n){
		memset(v,0,sizeof(v));
		for(int i=t;i<=n;i++){
			for(int j=t;j<i;j++){
				if(a[i]==a[j]&&!v[j]){
					for(int k=j;k<i;k++)v[k]=1; 
				}
			}	
		}
		for(int j=t;j<=n;j++)if(!v[j])b[a[j]]++;
		t++;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}


