#include<bits/stdc++.h>
using namespace std;
int a[500010],cnt[300010];
int f[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		stack<int> s;
		for(int j = 0;j <= m;j++)f[j]=false;
		for(int j = i;j < n;j++){
			if(!f[a[j]]){
				s.push(a[j]);
				f[a[j]]++;
			}else{
				while(s.top()!=a[j]){
					int t=s.top();
					f[t]--;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			int t=s.top();
			//cout << t << " ";
			cnt[t]++;
			s.pop();
		}
		//cout << endl;
	}
	for(int i = 1;i <= m;i++)cout << cnt[i] << " ";
	return 0;
}
