#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
int have(int s,vector<int>v){
	int wei=0;
	for(auto i:v){
		if(s==i){
			return wei;
		}
		wei++;
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	vector<int>v;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int h=have(a[j],v);
			if(h!=-1){
				int vs=v.size();
				for(int o=h;o<=vs;o++){
					v[o]=-1;
				}
				for(vector<int>::iterator it=v.begin();it!=v.end();){
					if(*it==-1){
						v.erase(it);
					}else{
						++it;
					}
				}
			}
			v.push_back(a[j]);
		}
		for(int j=1;j<=m;j++){
			if(have(j,v)!=-1)cnt[j]++;
		}

		for(vector<int>::iterator it=v.begin();it!=v.end();){
			v.erase(it);
		}
	}
	for(int j=1;j<=m;j++){
		cout << cnt[j] << ' ';
	}
	return 0;
}