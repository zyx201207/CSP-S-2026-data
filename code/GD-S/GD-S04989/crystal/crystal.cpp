#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,a[N],b[1000010],c[1000010],maxn;
void dfs(int x,int y){
	if(!x){
		for(int i=1;i<=n;i++){
			if(a[i]<0){
				c[-a[i]]++;
				if(c[-a[i]]>maxn)maxn=c[-a[i]];
			}
			else{
				b[a[i]]++;
				if(b[a[i]]>maxn)maxn=b[a[i]];
			}
		}
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		return; 
	}
	if(y>n)return;
	a[y]++;
	dfs(x-1,y);
	a[y]--;
	a[y+1]++;
	dfs(x-1,y+1);
	a[y+1]--;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(m,1);
	cout<<maxn;
	return 0;
} 
