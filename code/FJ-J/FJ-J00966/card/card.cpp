//CSP-J
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int p[100005];
vector<int>v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		v.clear();
		for(int j=i;j<=n;j++){
			for(int k=0;k<v.size();k++){
				if(v[k]==a[j]){
					int t=v.size();
					for(int l=k;l<t;l++){
						v.pop_back();
					}
					break;
				}
			}
			v.push_back(a[j]);
		}
		for(int j=0;j<v.size();j++){
			p[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<p[i]<<" ";
	return 0;
}
