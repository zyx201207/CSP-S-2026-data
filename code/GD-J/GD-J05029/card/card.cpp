#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m;
map<int,int> mp;
int a[N],c[N],s[N];
int maxn=0;
bool b[N];
bitset<N> bt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		map<int,int> mp;
		int s=0,e=0;
		bt=0;
		for(int j=i;j<=n;j++){
			if(bt[a[j]]==1){
				if(s==0) s=mp[a[j]];
				e=j;
			}
			bt[a[j]]=1;
			mp[a[j]]=j;
		}
		if(e==0 && s==0){
			for(int j=i;j<=n;j++) c[a[j]]++;
		}
		else{
			for(int j=e;j<=n;j++) c[a[j]]++;
			for(int j=i;j<s;j++) c[a[j]]++;			
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
