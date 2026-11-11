#include<bits/stdc++.h> 
using namespace std;
int a[200001],ans[200001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		vector<int> v;
		for(int j=i;j<=n;j++){
			auto f=find(v.begin(),v.end(),a[j]);
			if(f!=v.end()){
				v.erase(f,v.end());
			}
			v.push_back(a[j]);
		} 
		for(int j:v){
			ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout << ans[i] << ' ';
	return 0;
}
// 12/25 48·Ö 
