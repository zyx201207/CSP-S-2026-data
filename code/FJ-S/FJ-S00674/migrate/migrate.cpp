#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
int c,t;
int n,d,a[2000010];
struct ddd{
	int o,p;
};
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		vector<int> v[2000010];
		int sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(abs(a[i]-a[j])<=d){
					v[i].push_back(j);
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(auto j:v[i]){
//				cout<<j<<" ";
//			}
//			cout<<endl;
//		}
		for(int i=1;i<=n;i++){
			int st[2000010]={0};
			int lr[2000010]={0};
			queue<ddd> q;
			q.push({i,0});
			st[i]=-1;
			while(!q.empty()){
				auto b=q.front();
				q.pop();
				int w[2000010];

				for(auto k:v[b.o]){
					

					if(st[k]==0){
//					cout<<k<<" "<<st[k]<<endl;
						st[k]=b.p+1;
						q.push({k,b.p+1});
					}else if(st[k]==b.p+1){
						q.push({k,b.p+1});
						lr[k]+=1;
//						cout<<k<<" "<<lr[k]<<endl;
//						for(int j=1;j<=n;j++) cout<<lr[j]<<"  ";
						
					}
//			for(int j=1;j<=n;j++) cout<<st[j]<<" ";
//			cout<<endl;					
				}
//				cout<<sum<<endl;
			}
			for(int j=1;j<=n;j++) if(lr[j]==1) sum++;
			
//			cout<<endl;
		}
		cout<<sum/2<<endl;
	}
	return 0;
}
