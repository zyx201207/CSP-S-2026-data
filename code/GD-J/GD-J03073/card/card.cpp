#include<bits/stdc++.h>
using namespace std;
long long n,q[300010],m,o,p,s,w[100010],a[300010];
vector <long long >v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	for(int i=1;i<=n;i++){
		memset(w,0,sizeof(w));
		v.clear();
		for(int j=i;j<=n;j++){
			if(w[q[j]]==1){
				for(int k=0;k<v.size();k++){
					if(v[k]==q[j]){
						for(int l=v.size()-1;l>k;l){
							w[v[l]]=0;
							v.pop_back();
							if(v.size()==k){
								break;
							}
						}
						break;
					}
				}
			}
			v.push_back(q[j]);
			w[q[j]]=1;
		}
		for(int j=0;j<v.size();j++){
			cout<<v[j]<<" ";
			a[v[j]]+=1;
		}
		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
