#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long l[500005],ans[300005];
bool find(string s,int x){
	for(int i=0;i<s.size();i++){
		if(s[i]-'0' == x) return 1;
	}
	return 0;
}
int findi(string s,int x){
	for(int i=0;i<s.size();i++){
		if(s[i]-'0' == x) return i;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>l[i];
	for(int i=1;i<=n;i++){
			string s = "";
			for(int j=i;j<=n;j++){
				if(!find(s,l[j])) s+=l[j]+'0';
				else s = s.substr(0,findi(s,l[j])+1);
			}
			for(int j=1;j<=m;j++){
				if(find(s,j)) ans[j]++;
			}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
