#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<ll>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<ll>s(m+1,0);
	for(int i=1;i<=n;i++){
		vector<int>mp(m+1,-1);
		vector<ll>q(n+1);
		int t=0;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==-1){
				mp[a[j]]=++t;
				q[t]=a[j];
			}
			else{
				while(t>mp[a[j]]){
					mp[q[t]]=-1;
					t--;
				}
			}
		}
		for(int j=1;j<=t;j++){
			cout<<q[j]<<" ";
			s[q[j]]++;
		}
		cout<<"\n";
	} 
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}
