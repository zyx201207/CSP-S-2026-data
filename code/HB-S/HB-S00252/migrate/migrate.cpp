#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,d;
int x[N];
vector<int> adj[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
    scanf("%d %d",&c,&T);
    while(T--){
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                int len=x[i]-x[j];
                if(len>d)break;
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i-d;j++){
                set<int> s;
                int cnt=0;
                for(int k=0;k<adj[j].size();k++){
                    s.insert(adj[j][k]);
                }
                for(int k=0;k<adj[i].size();k++){
                    int len=s.size();
                    s.insert(adj[i][k]);
                    if(s.size()==len){
						cnt++;
					}
                }
                if(cnt==2)sum++;
            }
        }
        printf("%d\n",sum);
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
    }
	return 0;
}
