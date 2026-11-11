#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[300010],c[500010],cnt,pos[300010];
bool v[300010];
int main(){
	freopen("card.in","r",stdin);
   	freopen("card.out","w",stdout);
   	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		cnt=0;
		for(long long j=i;j<=n;j++){
			c[++cnt]=a[j];
			if(v[a[j]]){
				for(long long d=pos[a[j]];d<j;d++){
					c[d]=0;
					if(pos[c[d]]){
						pos[c[d]]=0;
					}
				}
				pos[a[j]]=0;
				v[a[j]]=0;
			}
			v[a[j]]=1;
			if(!pos[a[j]]){
				pos[a[j]]=j;
			}								
		}
		for(long long j=1;j<=cnt;j++){
			if(c[j]){
				b[c[j]]++; 
			}
			c[j]=0;
		}
		for(long long j=1;j<=m;j++){
			v[j]=0;
			c[j]=0;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
