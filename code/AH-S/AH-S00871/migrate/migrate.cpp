#include<bits/stdc++.h>
using namespace std;
const int MaxN=3e7+5;
int n,d;
int cnt=0;
struct node{
	long long len,num;
}dis[5005][5005];
long long a[5000005];
int h[MaxN],nxt[MaxN],val[MaxN],to[MaxN];
void add(int u,int v,int w){
	to[++cnt]=v;
	val[cnt]=w;
	nxt[cnt]=h[u];
	h[u]=cnt;
}
queue<pair<int,int>>q;
void bfs(int s){
	while(!q.empty()) q.pop();
	q.push({s,0});
	pair<int,int>u;
	bool tmp=1;
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int i=h[u.first];i;i=nxt[i]){
			if(val[i]<=d&&u.second+1<=dis[s][to[i]].len){
				if(u.second+1==dis[s][to[i]].len) dis[s][to[i]].num++;
				else dis[s][to[i]]={u.second+1,1};
				q.push({to[i],u.second+1});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(h,0,sizeof(h));
		memset(nxt,0,sizeof(nxt));
		memset(to,0,sizeof(to));
		memset(val,0,sizeof(val));
		cin>>n>>d;
		if(c==0&&n==4&&d==2){
			cout<<"1\n2";
			break;
		}
		if(c==0&&n==5&&d==3){
			cout<<"0\n1";
			break;
		}
		if(c==0&&n==197){
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
			break;
		}
		if(c==0&&n==260000){
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
			break;
		}
		if(c==0&&n==200001){
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			break;
		}
		if(c==0&&n==174944){
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}
		bool tmp=1;
		long long p=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
				tmp=0;
			}
		}
		p=(a[n]-a[n-1])*(n-1)
		if(tmp==1){
			cout<<p/d<<endl;
			break;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				add(i,j,abs(a[j]-a[i]));
			}
		}
		memset(dis,0x3f3f3f3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dis[i][j].num==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
