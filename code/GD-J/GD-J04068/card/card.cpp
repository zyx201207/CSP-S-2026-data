#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5*1e5+5;
int n,m,ed;
int cd[N],ps[N],cont[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>cont[i];
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			int a=cont[i];
			if(ps[a]!=0&&ps[a]<=ed)	ed=ps[a];
			else ps[a]=++ed;
			cd[ed]=a;
		}
		for(int i=1;i<=ed;i++)	ans[cd[i]]++;
		for(int i=1;i<=n;i++)	cd[i]=0;
		for(int i=1;i<=n;i++)	ps[i]=0;
		ed=0;
	}
	for(int i=1;i<=m;i++)	cout<<ans[i]<<' ';
	return 0;
}
