#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
const int N=6e5+5;
int read(){
	char c=getchar();
	int k=0;
	while(c>='0'&&c<='9'){
		k=k*10+(c-'0');
		c=getchar();
	}
	return k;
}
void print(int x){
	if(x/10)print(x/10);
	putchar((x%10)+'0');
}
int c,n,m,d,que,vis[N],ans,w[N],mem[505][500005];
vector<pi> a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();que=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int z=read(),t=read();
			a[m+i].push_back({z,t});
			a[z].push_back({m+i,t});
		}
	}
	for(int i=1;i<=n;i++){
		queue<pi> q;
		q.push({m+i,0});
		while(!q.empty()){
			pi tem=q.front();
			q.pop();
			if(mem[i][tem.first]&&tem.second>mem[i][tem.first])continue;
			mem[i][tem.first]=tem.second;
			for(pi i:a[tem.first]){
				q.push({i.first,tem.second+i.second});
			}
		}
	}
	while(que--){
		ans=INT_MAX;
		int x=read(),y=read();
		for(pi i:a[x]){
			ans=min(ans,i.second+mem[i.first-m][y]);
		}
		print(ans+w[x]+w[y]);putchar('\n');
//		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
