#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=3e5+5;
int n,m,a[N],c[N],p[N];
bool b[N],f[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=1;
	while(cnt<=n){
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		for(int i=cnt;i<=n;i++){
			if(b[a[i]]==1){
				for(int j=p[a[i]];j<i;j++){
					b[a[j]]=0;
				}
				b[a[i]]=1;
			}else{
				b[a[i]]=1;
				p[a[i]]=i;
			}
		}
		for(int i=cnt;i<=n;i++){
			if(f[a[i]]) continue;
			c[a[i]]+=b[a[i]];
			f[a[i]]=1;
		}
		cnt++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
