#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,ans;
string s;
struct node{
	string s;
	int d;
	bool lr;
}f[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i].d>>f[i].s;
		while(f[i].d--){
			s+=f[i].s;
		}
	} 
	int k=s.size();
	for(int i=0;i<k/2;i++){
		if(s[i]!=s[k-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
