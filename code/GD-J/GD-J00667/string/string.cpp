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
Node st[1000000];
char nums[1000000];
int main(){
	fileIO("string");
	fastIO();
	int n;
	cin >> n;
	int ai;
	char ci;
	ll len = 0;
	
//	for (int i = 0;i<n;i++){
//		cin >> st[i].c >> st[i].n;
//		len+=st[i].n;
//	}
//	for (int i = 0;i<n;i++){
//		if (st[i].c!=st[n-1-i].c){
//			if (st[i].n>st[n-1-i].n){
//				while()
//			}
//		}
//	}
	ll leng = 0;
	int ii = 1;
	for (int i = 0;i<n;i++){
		cin >> ai >> ci;
		for (int j = 1;j<=ai;j++){
			nums[ii] = ci;
			ii++;
			leng++;
		}
	}
	int res = 0;
	for (int i = 1;i<=leng/2;i++){
		if (nums[i] != nums[leng+1-i]){
			res++;
		}
	}
	cout << res;
	
	
	
	return 0;
}
