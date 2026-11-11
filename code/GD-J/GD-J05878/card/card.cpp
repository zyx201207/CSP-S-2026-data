#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long n,m,t;
long long a[N],b[N],c[N],d[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	t=n;
	while(n--){
		for(int i=t-n+1;i<=t;i++){
			for(long long j=1;j<=N*N;j++){
				if(c[j]==0){
					c[j]=a[i];
					for(int x=1;x<j;x++){
						if(c[x]==c[j]){
							c[x]=c[j];
							for(int p=x+1;p<=j;p++){
								c[p]=0;
							}
						}
					}
					break;
				}
			}			
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(c[j]==i){
					d[i]+=1;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i];
	}
	return 0;
} 
