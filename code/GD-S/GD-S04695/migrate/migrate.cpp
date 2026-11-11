#include<bits/stdc++.h>
using namespace std;
const int N=200001;
struct island{
	int len;
	int to;
};
vector<island> v[N];
int n,d,cnt;
long long x[N];
void connect(int a){
	int f[N],c[N];
	bool vis[N];
	queue<int>q;
	q.push(a);
	memset(f,0x3f,sizeof(f));
	f[a]=1;
	c[a]=1;
	vis[a]=1;
	while(!q.empty()){
		int Q=q.front();
		q.pop();
		for(int i=0;i<v[Q].size();i++){
			int to=v[Q][i].to;
			if(!vis[to]){
				q.push(to);
				if(f[Q]+1==f[to]){
					c[to]++;
				}
				else{
					c[to]=1;
					f[to]=min(f[to],f[Q]+1);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(c[n]==2) cnt++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t){
		t--;
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]<=d){
					v[j].push_back((island){2,i});
				}
			}
		}
		for(int i=1;i<=n;i++){
			connect(i);
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
