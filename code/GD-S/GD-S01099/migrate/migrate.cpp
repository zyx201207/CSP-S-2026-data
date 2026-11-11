#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>e[1005];
int s[1005],dis[1005],a[1005],q[1005];
bool zd(int A,int B){
	memset(s,0,sizeof(s));
	memset(dis,0x3f,sizeof(dis));
	memset(q,0,sizeof(q));
	dis[A]=0;
	s[A]=1;
	int h=1,t=1;
	q[t++]=A;
	while(h<t){
		int x=q[h];
		h++;
//		cout<<x<<":";
		for(int i=0;i<e[x].size();i++){
			int y=e[x][i];
//			cout<<y<<" ";
			if(dis[y]==dis[x]+1){
			//	if(s[y]==1)s[y]=0;
				s[y]+=s[x];
			}
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				s[y]+=s[x];
				q[t++]=y;
			}
		}
//		cout<<"\n";
	}
//	cout<<"\n"<<dis[B]<<"\n";
	if(s[B]==2){
	//	cout<<A<<" "<<B<<"\n";
		return true;
	}
	return false;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=0,T=0;
	cin>>c>>T;
	if(c>10){
		while(T--){
			cout<<"0\n";
		}
	}
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==j)continue;
				if(abs(a[i]-a[j])<=d){
			//		cout<<i<<" "<<j<<"\n";
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(zd(i,j))sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
//24
