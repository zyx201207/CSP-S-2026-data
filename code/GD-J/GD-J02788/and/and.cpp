#include<bits/stdc++.h>
using namespace std;
int n,d[300005],m,k,l,ans,p=1,i,t1,ok=1,e1,T=0;
multiset<int> st;
void c(int e,int t){
	//cout<<e<<' '<<t<<' '<<ans<<'\n';
	vector<int> v(31,0);
	vector<vector<int>> f(31,vector<int>());
	for(auto o=st.begin();o!=st.end();o++){
		k=*o;i=k;
//		cout<<k<<' ';
		l=0;
		for(;k!=0;){
			v[l]+=k&1;
			if(k&1){
				f[l].push_back(i);
			}
			k>>=1;
			l++;
		}
	}t1=t;
//	cout<<'\n';
	for(int o=31;o>=0;o--){//cout<<o<<' '<<v[o]<<'\n';
		if(v[o]>=m&&t1--==0){
			//cout<<'\n'<<o<<' '<<f[o].size()<<'\n';
			st.clear();
			for(auto j=f[o].begin();j!=f[o].end();j++){
				st.insert(*j);
			}
			if(v[o]>m){
				e1=f[o].size();ok=1;return;
			}else{
				ok=0;return;
			}
		}
	}ok=0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
	cin>>n>>m;
	//cout<<n<<' '<<m<<'\n';
	for(int o=1;o<=n;o++){
		cin>>d[o];//eraes
		st.insert(d[o]);
	}
	e1=n;
	for(;;){
		if(ok){
			c(e1,T++);
		}else{
			break;
		}
	}
	ans=0x3FFFFFFF;
	for(auto o=st.begin();o!=st.end();o++){
		k=*o;
		//cout<<k<<' ';
		ans&=k;
	}
	cout<<ans;
	return 0;
}
