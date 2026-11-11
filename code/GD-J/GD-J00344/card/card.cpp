#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt;
vector<int> v;
int sum[300010];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		v.clear();cnt = 0;
		for(int j = i;j <= n;j++){
			if(find(v.begin(),v.end(),a[j]) != v.end())v.erase(find(v.begin(),v.end(),a[j]),v.end());
			v.push_back(a[j]);
			
		}
		for(int j : v){
			sum[j]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << sum[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
