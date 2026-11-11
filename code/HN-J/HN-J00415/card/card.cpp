#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
#define ll long long
ll n,m,a[MAXN],d[MAXN];
ll v[MAXN];
bool b[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int w=1;w<=n;w++){
		for(int i=1;i<=n;i++){
			d[i]=a[i];
			b[i]=0;
		}
		for(int i=w;i<=n;i++){
			for(int j=w;j<i;j++){
				if(d[i]==d[j]){
					for(int k=j;k<i;k++){
						d[k]=0;
					}
					break;
				}
			}
		}
		for(int i=w;i<=n;i++){
			if(b[d[i]]==false ){
				v[d[i]]+=1;
				b[d[i]]=true;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<v[i]<<" ";
	return 0;
}
