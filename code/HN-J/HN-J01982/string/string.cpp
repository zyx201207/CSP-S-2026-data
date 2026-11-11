#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
char c;
string s;
int dfs(long long l,long long r){
	if(l==r){
		return 0; 
	}else if(r-l==1&&s[l]==s[r]){
		return 0;
	}
	if(s[l]!=s[r]){
		s[r]=s[l];
		ans++;
		dfs(l+1,r-1);
	}
}
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s=s+c;
		}
    }
    dfs(0,s.size()-1);
    cout<<ans;
	return 0;
}
