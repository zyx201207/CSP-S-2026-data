#include<bits/stdc++.h>
using namespace std;
int sum[20005];
int a[20005];
int n,d;
struct point{
	int u,w;
};
bool operator <(point a,point b){
	return a.w>b.w;
}
int dij(int u,int v){
	//cout<<"dij "<<u<<' '<<v<<endl;
	int res=0,mx=0x3f3f3f3f;
	priority_queue<point>q;
	q.push({u,0});
	while(!q.empty()){
		//if(q.size()>10)return 10;
		point now=q.top();
		//cout<<now.u<<' '<<now.w<<endl;
		//if(now.w>10)return 0;
		q.pop();
		if(now.u==v){
			if(now.w<=mx)mx=now.w;
			if(now.w>mx)continue;
			res++;
			if(res>2)break;
			//cout<<u<<' '<<v<<' '<<now.w<<endl;
			continue;
		}
		//if(now.w>mx+1)continue;
		for(int i=now.u+1;i<=v;i++){
			if(sum[i-1]-sum[now.u-1]<=d){
				q.push({i,now.w+1});
				//cout<<now.u<<' '<<i<<"   ";
			}
			else break;
			
		}
	}
	return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			sum[i]=sum[i-1]+a[i+1]-a[i];
		}
		int ans=0;
		int l=1,r=1;
			while(1){
				int no=dij(l,r);
				//cout<<l<<' '<<r<<' '<<no<<endl;
				if(no==2){
					for(int i=l+1;i<=r;i++){
						if(dij(i,r)!=2){
							//cout<<"ans:"<<ans<<' '<<i-l<<endl;
							ans+=i-l;
							l=i;
							break;
						}
					}
					for(int j=r+1;j<=n;j++){
						if(dij(l-1,j)!=2){
							//cout<<"ans:"<<ans<<' '<<j-r-1<<endl;
							ans+=j-r-1;
							r=j;
							break;
						}
					}
				}
				if(no>2){
					l=r;
				}
				if(no<2){
					r++;
				}
				if(r>n)break;
			}
		
		cout<<ans<<endl;
	}
	return 0;
}
