#include <iostream>
#include <stack>
using namespace std;
int n,m;
int a[500005];
stack<int> s;
bool ds[500005];
int cnt[500005];
void play(int i){
	for(int x = 1;x <= n;x++){
		ds[x] = 0;
	}
	for(int j = i;j <= n;j++){
		if(ds[a[j]] != 0){
			int t = s.top();
			while(t!=a[j]){
				ds[t] = 0;
				s.pop();
				t = s.top();
			}
		}
		else{
			s.push(a[j]);
			ds[a[j]] = 1;
		}
	}
	for(int x = 1;x <= n;x++){
		if(ds[x] == 1){
			cnt[x]++;
		}
	}
	while(!s.empty()){
		s.pop();
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		play(i);
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] <<" ";
	}
	return 0;
}

