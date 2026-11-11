#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n ,m;
int a[N] ,ans[100];
vector<int> v[100];
int init(int x){
	int t=0;
	int tmp=x;
	do{
		int r=x%2;
		if(r==1){
			ans[t]++;
			v[t].push_back(tmp);
			t++;
		} 
		else t++;
		x /= 2;
	}while(x);
	return t-1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in" ,"r" ,stdin);
	freopen("and.out" ,"w" ,stdout);
	cin >> n >> m;
	int Max=0;
	for(int i=1;i <= n;i++){
		cin >> a[i];
		int t=init(a[i]);
		Max=max(Max ,t);
	}
	for(int i=Max;i >= 0;i--){
		if(ans[i] >= m){
			ll res=v[i][0];
			for(auto j:v[i]){
				res=res&j;
			}
			cout << res << '\n';
			return 0;
		}
	}
	return 0;
} 


