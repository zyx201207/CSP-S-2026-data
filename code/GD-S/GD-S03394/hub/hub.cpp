#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
struct Node{
	int x,y;
}s[MAXN];
int n,k,c[MAXN],b[MAXN];
bool cmp(Node xx,Node yy){
	if(xx.x!=yy.x)return xx.x<yy.x;
	return xx.y<yy.y;
}
void solve(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)c[i]=0;
	for(int i=1;i<n;i++){
		scanf("%d %d",&s[i].x,&s[i].y);
		if(s[i].x>s[i].y)swap(s[i].x,s[i].y);
		c[s[i].x]++,c[s[i].y]++;
	}
	if(k<=2){
		printf("%d\n",k-1);
		return;
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++)b[1]=max(b[1],c[i]);
	if(k<=b[1]/2){
		printf("2\n");
		return ;
	}
	printf("%d\n",k-1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--)solve();
	return 0;
}
