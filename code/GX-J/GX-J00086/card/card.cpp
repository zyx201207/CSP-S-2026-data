#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int n,m,res;
int a[500005];
int ans[300005];
vector<int> v;
unordered_set<int> st;
inline char itc(int x){
	return char('0'+x);
}
inline int cti(char ch){
	return ch-'0';
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		v.clear();
		st.clear();
		for(int j=i;j<=n;++j){
			bool found=st.find(a[j])!=st.end();
			if(found){
				while(v.back()!=a[j]){
					st.erase(v.back());
					v.pop_back();
				}
				st.erase(v.back());
				v.pop_back();
			}
			v.push_back(a[j]);
			st.insert(a[j]);
		}
		for(int i=1;i<=m;++i) if(st.find(i)!=st.end()){
			++ans[i];
		}
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<' ';
	return 0;
}
