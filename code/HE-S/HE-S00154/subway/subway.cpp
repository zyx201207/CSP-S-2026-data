#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int c,n,m,d,q;
struct subw{
	int w,id;
	bool a[22];
	int t[22];
} s[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s[i].w;
		s[i].id=i;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a1;
			cin>>a1;
			s[j].a[ai]=true;
			cin>>s[j].t[ai];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int step[500005];
		bool vis[500005];
		queue<subw> q;
		q.push(s[x]);
		vis[x]=1;
		while(true){
			int z=q.front();
			q.pop();
			if(z.id==s[y].id){
				cout<<step[z]+1;
				break;
			}
			else{
				for(int j=1;j<=21;j++){
					if(z.a[j]){
						
					}
				}
			}
		}
	}
	return 0;
}
