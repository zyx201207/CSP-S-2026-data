#include<bits/stdc++.h>
using namespace std;
bool mp[500050];
stack<int> st;
int cnt[500050];
int n,m;
int a[500050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(long long i=1;i<=n;i++){
		memset(mp,0,sizeof(mp));
		for(long long j=i;j<=n;j++){
			if(mp[a[j]]==1){
				while(st.size()){
					long long d=st.top();
					mp[d]=0;
					st.pop();
					if(d==a[j]){
						break;
					}
				}
			}
			st.push(a[j]);
			mp[a[j]]=1;	
		}
		while(st.size()){
			long long d=st.top();
			cnt[d]++;
			st.pop();
			
		}
		
	}
	for(long long i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}

