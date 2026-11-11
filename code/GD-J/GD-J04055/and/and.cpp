#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void dyr(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> cnt(35);
	vector<vector<int>> a(n+1);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int now=0;
		while(k){
			if(k%2==1){
				cnt[now].push_back(i);
				a[i].push_back(now);
			} 
			now++;
			k/=2;
		}
	}
	ll ans=0; 
	for(int i=32;i>=0;i--){
		if(cnt[i].size()>=m){
			ans+=(1<<i); 
			vector<vector<int>> add(35);
			for(int it:cnt[i]){
				for(auto itt:a[it]){
					add[itt].push_back(it); 
				}
			}cnt=add;
		}
	}cout<<ans;
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	dyr();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

