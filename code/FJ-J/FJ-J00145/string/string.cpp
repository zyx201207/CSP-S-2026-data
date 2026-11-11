#include<bits/stdc++.h>
using namespace std;
long long ans = 1e9+5,l;
bool think(string s){
	string back;
	for(long long i=l-1;i>0;i--){
		back+=s[i];
	}
	if(back==s)return true;
	return false;
}
void dfs(long long id,string s,long long sum){
	if(think(s)){
		ans = min(ans,sum);
		return;
	}
	for(int j='a';j<='z';j++){
		if(s[id]==j){
			dfs(id+1,s,sum);
		}else{
			char before = s[id];
			s[id] = j;
			dfs(id+1,s,sum+1);
			s[id] = before;	
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;cin >> n;
	string s;
	for(long long i=1;i<=n;i++){
		long long a;char b;cin >> a >> b;
		for(long long i=1;i<=a;i++){
			s+=b;
		}
	}
	l = s.size();
	for(long long i=0;i<l;i++){
		dfs(i,s,0);
	}
	cout << ans << "\n";
	return 0;
}
