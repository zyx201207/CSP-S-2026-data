#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int read(){
	int t;
	scanf("%d",&t);
	return t;
} 
int n,m;
int a[maxn];
int ans[maxn];
vector<int> e[maxn];
int head[maxn],tail[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		e[a[i]].push_back(i);
		tail[a[i]]++;
	}
	int pos1=n,pos2=0;
	for(int i=1;i<=m;i++){
		if(tail[i]<=1) continue;
		if(e[i][1]<pos1){
			pos1=e[i][1];
			pos2=e[i][0];
		}
	}
	for(int i=1;i<pos2;i++){
		head[a[i]]++;
		if(head[a[i]]==tail[a[i]]){
			ans[a[i]]+=i;
		}
	}
	int d=pos2;
	while(pos2<=n){
		head[a[pos2]]++;
		pos2++; 
		while((tail[a[pos2]]-head[a[pos2]])<=1 && pos2<pos1){
			ans[a[pos2]]=pos2-d;
			pos2++;
		}
		if(pos2==pos1){
			while((tail[a[pos2]]-head[a[pos2]])<=1 && pos2<n){
				ans[a[pos2]]=pos2-d+1;
				pos2++;
			}
			if(pos2!=n){
				pos1=e[a[pos2]][head[a[pos2]]+1];
				d=pos2;
			}
		}
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
