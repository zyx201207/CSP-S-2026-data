#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],cnt[N];
set<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		st.clear();
		for(int j=i;j<=n;j++){
			if(st.count(a[j])){
				for(int k=j-1;k>=i;k--){
					if(a[k]==a[j]){
						break;
					}
					st.erase(a[k]);
				}
			}
			st.insert(a[j]);
		}
		for(int j=1;j<=m;j++){
			if(st.count(j))cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
