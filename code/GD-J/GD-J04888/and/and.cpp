#include <bits/stdc++.h>
using namespace std;

bool get_number(long long num,int w){
	return num & (long long)pow(2,w);
}

long long n,m;
int can[31];
vector<long long> V[2];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int now_use;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> now_use;
		V[0].push_back(now_use);
	}
	now_use = 0;
	for(int i = 30;i >= 0;i--){
		for(int j = 0;j < (int)V[now_use].size();j++){
			if(get_number(V[now_use][j],i)){
				V[now_use ? 0 : 1].push_back(V[now_use][j]);
			}
		}
		if(V[now_use ? 0 : 1].size() >= m){
			V[now_use].clear();
			now_use = now_use ? 0 : 1;
			can[i] = 1;
		}else{
			V[now_use ? 0 : 1].clear();
		}
	}
	n = 0;
	for(int i = 0;i < 31;i++){
		n += can[i] * (long long)pow(2,i);
	}
	cout << n;
}
