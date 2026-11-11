#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,max_length=0;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		max_length=max(max_length,(int)log2(a[i])+1);
	}
	vector<int>b;
	for(int i=max_length;i>=0;i--){
		b.clear();
		for(int j=0;j<a.size();j++){
			if(a[j]&1<<i){
				b.push_back(a[j]);
			}
		}
		if(b.size()<m){
			continue;
		}
		else{
			a=b;
		}
	}
	int out=a[0];
	for(int i=0;i<m;i++){
		out&=a[i];
	}
	cout<<out;
	return 0;
}
//dp.
//?
/*
let dp[i][j]means from 0~i,use j numbers'maxnum.
maybe it is wrong?
yes,it will.
?!!!!!
maybe i need to use dfs to get a little score.
it takes ?!
or 
->this is mostly the right answer.
check the bits.
if one bit can let some of them done,but if their numbers < m ,kick it.
Ah!!!
Done it!

*/
