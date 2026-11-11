#include<bits/stdc++.h>
using namespace std;
const int ml=2*1e5+5;
unordered_map<int,int> t,ans;
long long n,a[ml],m;
int main() {
	freopen("card4.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=n; i++) {
		vector<int> h,z;
		t.clear();
		for(int j=i; j<=n; j++)h.push_back(a[j]);
		for(auto x:h) {
			if(t[x]==1) {
				int it=0;
				for(int i=0; i<z.size(); i++) {
					if(z[i]==x) {
						it=i;
						break;
					}
				}
				for(int i=it; i<z.size(); i++)t[z[i]]=0;
				z.erase(z.begin()+it,z.end());
			}
			z.push_back(x);
			t[x]++;
		}
		for(auto x:t) {
			if(x.second==1){
				ans[x.first]++;
			}
		}
		z.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

