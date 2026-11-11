#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+114514;
int n,m,a[N],ans;
vector<int> cf,b[91],hx;
signed main(){
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int tmp=a[i];
		while(tmp)cf.push_back(tmp%2),tmp/=2;
		for(int j=0;j<cf.size();j++)if(cf[j])b[j].push_back(a[i]);
		
		//reverse(cf.begin(),cf.end());
		/*for(auto x:cf)cout<<x;
		cout<<"\n";*/
		cf.clear();
	}
	/*for(int i=3;i>=0;i--,cout<<'\n'){
		cout<<"可以贡献 "<<(1<<i)<<" 的："; 
		for(auto x:b[i])cout<<x<<" ";
	}*/
	
	
	for(int i=31;i>=0;i--){
		if(b[i].size()>=m){
			ans+=(1<<i);
			hx.clear();
			for(auto x:b[i])hx.push_back(x);
			for(int j=0;j<=31;j++)b[j].clear();
			for(auto x:hx){
				int tmp=x;
				while(tmp)cf.push_back(tmp%2),tmp/=2;
				for(int j=0;j<cf.size();j++)if(cf[j])b[j].push_back(x);
				cf.clear();
			}
		}
	}
	cout<<ans;
	
	return 0;
}
//luogu 991587
//florr is a trash game
//m28
//genshin impact
//676767
//10s 出思路 40 min 出代码我太菜了 /ll 
