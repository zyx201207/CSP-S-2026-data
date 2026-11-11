#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
int n,m,top,a[MAXN],ans[MAXN],st[MAXN],mp[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin >> n >> m;
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	for(int i = 1;i<=n;i++){
		top = 0;
		for(int j = 1;j<=n;j++) mp[j] = -1,st[j] = 0;
		for(int j = i;j<=n;j++){
			if(mp[a[j]]!=-1){
				while(top>mp[a[j]]) mp[st[top]] = -1,top--;
				top--;
			} 
			st[++top] = a[j],mp[a[j]] = top;
		}
		for(int j = 1;j<=top;j++) mp[st[j]] = 0x3f3f3f3f;
		for(int j = 1;j<=m;j++)
			if(mp[j]==0x3f3f3f3f) ans[j]++;
	}
	for(int i = 1;i<=m;i++) printf("%d ",ans[i]); 
	return 0;
}
