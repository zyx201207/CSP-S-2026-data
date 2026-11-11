#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fileIO(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
}
struct Node{
	char c;
	int n;
};

ll f[1000000];
int vis[100000];
int n,m;
ll nums[1000000];
int step = 0;
ll anweiyu(ll a,ll b){
	int base = 0;
	ll res=0;
	while(a>0 && b>0){
		int a1 = a%2;
		int b1 = b%2;
		int c1 = a1&&b1;
		if (base == 0){
			res += c1*1;
		}
		else{
			for (int i = 0;i<base;i++){
			c1*=2;
			}
			res+=c1;
		}
		base++;
		a/=2;
		b/=2;
		
	}
	return res;
}


Node st[1000000];

int main(){
	fileIO("and");
	fastIO();
	cin >> n >> m;
	ll maxi = 0;
	for (int i = 0;i<n;i++){
		cin >> nums[i];
		maxi = max(maxi,nums[i]);
	}
	if (m == 1){
		cout << maxi;
	}
	ll maxyu;
	if (m == 2){
		for (int i = 0;i<n-1;i++){
			for (int j = i+1;j<n;j++){
				maxyu = max(maxyu,anweiyu(nums[i],nums[j]));
			}
		}
		cout << maxyu;
	}
	
	
	return 0;
}
