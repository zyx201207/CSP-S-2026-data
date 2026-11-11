#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int las[300010],b[500010],c[300010];
bool la[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		las[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		la[las[i]]=1;
	}
	for(int i=1;i<=n;i++){
		b[i]=1;
		if(la[i-1]){
			b[i]+=c[a[i-1]];
		}
		c[a[i]]+=b[i];
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
