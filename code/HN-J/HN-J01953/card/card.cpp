#include<bits/stdc++.h>
using namespace std;
int a[50005],b[50005],on[50005],k[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,t=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)b[i]=a[i];
		for(int j=i;j<=n;j++){
			on[t]=b[j];
			t++;
			for(int w=1;w<t-1;w++){
				if(on[w]==on[t] && on[w]!=0){
					//cout<<'@';
					for(int u=w+1;u<=t;u++){
						on[u]=0;
					}
					t=w;
				}
			}
		}
		for(int j=1;j<=t;j++){
			//cout<<on[j]<<' ';
			k[on[j]]++;
		}	
		//cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		if(k[i]>n)k[i]=n;
		cout<<k[i]<<" ";
	}
	return 0;
} 
