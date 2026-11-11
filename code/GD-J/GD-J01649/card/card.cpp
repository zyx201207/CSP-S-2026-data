#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[500005];
int pa[300005];
int vi[300005];
int lp[300005];
set<int>st;
int R=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>mp[i];
	for(int i=1;i<=n;i++){
		R=0;
		st.clear();
		for(int j=i;j<=n;j++){
			if(!st.count(mp[j])){
				pa[++R]=mp[j];
				vi[mp[j]]=R;
				st.insert(mp[j]);
			}else{
				while(R!=vi[mp[j]]){
					st.erase(mp[R]);
					R--;
				}
			}
			
		}
		for(int j=1;j<=R;j++){
			lp[pa[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
	 	cout<<lp[i]<<" ";
	}
}
