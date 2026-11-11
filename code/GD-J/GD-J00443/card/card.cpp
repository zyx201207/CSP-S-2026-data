#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	
	cin >> n >> m;
	vector<int> c(n + 1,0);
	vector<int> cnt(m + 1,0);
	vector<int> ans(m + 1,0);
	
	for(int i = 1;i<=n;i++)
	{
		cin >> c[i];
	}
	for(int i = 1;i<=n;i++){
		queue<int> pp;
		vector<bool> p(m + 1,false);
		for(int j = i;j<=n;j++){
			if(cnt[c[j]] == 0){
				cnt[c[j]]++;
				p[c[j]] = true;
				pp.push(c[j]);
			}
			else{
				while(pp.empty() == false && pp.front()!=c[j])
				{
					if(cnt[pp.front()] > 0) cnt[pp.front()]--;
					if(cnt[pp.front()] == 0) p[pp.front()] = false;
					pp.pop();
				}
			}
		}
		while(pp.empty() == false){
			ans[pp.front()] += 1;
			pp.pop();
		}
	}
	for(int i = 1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
