#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],k[501],x,y,y11;
bool ta=1,tb=1;
vector<int>a[501];
vector<int>b[501];
struct stu{
	int s,t;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2){
			ta=0;
		}
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			if(i==1&&j==1){
				y11=y;
			}
			if(y!=y11){
				tb=0;
			}
			a[i].push_back(x);
			b[i].push_back(y);
		}
	}
	if(ta==1){
		
	}
	if(tb==1){
		queue<stu>f;
		stu u;
		int vis[500001]={};
		while(q--){
			cin>>x>>y;
			f.push({x,0});
			vis[x]=1;
			while(f.size()!=0){
				u=f.front();
				f.pop();
				if(u.s==y){
					while(f.size()!=0){
						f.pop();
					}
					cout<<u.t*y11*2+w[x]+w[y]<<"\n";
					break;
				}
				bool e=0;
				for(int i=1;i<=n;i++){
					for(int j=0;j<a[i].size();j++){
						if(a[i][j]==u.s){
							e=1;
							break;
						}
					}
					if(e==1){
						for(int j=0;j<a[i].size();j++){
							if(vis[a[i][j]]==0){
								f.push({a[i][j],u.t+1});
								vis[a[i][j]]=1;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
