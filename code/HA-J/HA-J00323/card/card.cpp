#include<bits/stdc++.h>
using namespace std;

map<int,int> s;
int n,m,A[500005],B[300005];
bool vis[300005];
vector<int> a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s[A[j]]==0){
				s[A[j]]=1;
				a.push_back(A[j]);
			}else{
				while(1){
					if(a[a.size()-1]==A[j]){
						break;
					}else{
						s[a[a.size()-1]]=0;
						a.pop_back();
					}
				}
			}
		}
		memset(vis,0,sizeof(vis));
		for(auto t:s){
			if(t.second==0){
				continue;
			}
			if(vis[t.first]==0){
				B[t.first]++;
				vis[t.first]=1;
			}
		}
		s.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<B[i]<<" ";
	}
}
