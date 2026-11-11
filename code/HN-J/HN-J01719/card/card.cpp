#include<bits/stdc++.h>
#define qwq return 0;
using namespace std;
int n,m,a[100005],ans[100005],v[100005],s[100005],h;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;j++){
			int x=h+1;
			for(int k=1;k<=h;k++){
				if(s[k]==a[j]){
					x=k;
					break;
				}
			}
			h=x-1,s[++h]=a[j];
		}
		for(int j=1;j<=h;j++) ++ans[s[j]];
		memset(s,0,sizeof(s));
	}	
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	qwq
}
//Trick||Treat!
//RP++
//Ô¤¼Æ24%pts
//O(n*m*m)<¸´ÔÓ¶È<O(n*n*m) 
