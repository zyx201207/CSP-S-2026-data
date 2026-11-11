#include <bits/stdc++.h>
using namespace std;
int a[500010],cnt[300010];
bool f[300010];
stack<int> s;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			int b = a[j];
			if(f[b] == false){
				s.push(b);
				f[b] = true;
			}
			else{
				while(s.top() != b){
					s.pop();
				}
			}
		}
		while(s.size() != 0){
			cnt[s.top()]++;
			s.pop();
		}
		for(int j = 1;j <= n;j++){
			f[j] = false;
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<cnt[i]<<" ";
	}
	cout<<endl;
	return 0;
}
