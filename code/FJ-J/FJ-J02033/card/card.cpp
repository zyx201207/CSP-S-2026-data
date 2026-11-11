#include<bits/stdc++.h>
using namespace std;
long long ans[300005];
long long a[500005];
long long is_a[500005];
vector<long long> now;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		is_a[i]=0;
		ans[i]=0;
	}
	for(int i=n;i>=1;i--){
		if(i==n){
			is_a[a[i]]++;
			ans[a[i]]++;
			now.push_back(a[i]);
			continue;
		}
		else{
			if(is_a[a[i]]!=0){
				while(!now.empty() && now.back()!=a[i]){
					is_a[now.back()]--;
					now.pop_back();
				}
				for(int i=0;i<now.size();i++)ans[now[i]]++;
			}
			else {
				now.push_back(a[i]);
				for(int i=0;i<now.size();i++)ans[now[i]]++;
				is_a[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
