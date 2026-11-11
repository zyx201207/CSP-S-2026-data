#include<bits/stdc++.h>
using namespace std;
const int N=5e5+500;
int a[N],jump[N],to[N];
int f[N];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=n;i>=1;i--){
    	if(!jump[a[i]])jump[a[i]]=i;
    	to[i]=jump[a[i]];
	}
	for(int i=1;i<=n;i++){
		f[to[i]]++;
		if(jump[a[i-1]]==i-1){
			f[to[i]]+=f[i-1];
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",f[jump[i]]);
	return 0;
}

