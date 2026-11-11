#include<bits/stdc++.h>
using namespace std;
int n,d,c,t,a[100000],mn=1e8,aannss;
vector<int> v;
vector<vector<int> > ans;
void dfs(int x,int s,int t,int st){
	if(x>t) return;
	if(x==t){
		if(st<mn){
			ans.clear();mn=st;
		}else if(st>mn) return;
		ans.push_back(v);return;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d){
			v.push_back(i);
			dfs(i,s,t,st+1);
			v.pop_back();
		}else break;
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		mn=1e8;aannss=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				mn=1e8;
				//cout<<i<<" "<<j<<endl;
				ans.clear();
				dfs(i,i,j,0);
				//cout<<ans.size()<<endl;
				if(ans.size()<=1) continue;
				bool f=0;
				if(mn==1) continue;
				//cout<<ans.size()<<endl;
				for(auto x:ans){
					if(f==1) break;
					//for(auto aa:x){
					//	cout<<aa<<' ';
					//}cout<<endl;
					for(auto y:ans){
						//if(x==y) continue;
						set<int> st;
						for(auto aa:x){
							if(aa==j) break;
							st.insert(aa);
						}
						for(auto aa:y){
							if(aa==j) break;
							st.insert(aa);
						}
						if((int)st.size()==2*mn-2){
							//cout<<i<<" "<<j<<endl;
							aannss++;f=1;break;
						}
					}
				}
			}
		}
		cout<<aannss<<endl;
	}
	return 0;
}
