#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000+10];
map<int,int>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		set<int>st;
		for(int j=i;j<=n;j++){
			if(st.count(a[j])){
				for(int k=i;k<j;k++){
					st.erase(a[k]);
				}
				st.insert(a[j]);
			}
			else {
				st.insert(a[j]);
			}
		}
		for(int j=i;j<=n;j++){
			if(st.count(a[j])){
				mp[a[j]]++;
				st.erase(a[j]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(mp[i])cout<<mp[i]<<" ";
	}
}
