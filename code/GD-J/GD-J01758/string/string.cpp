#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l,n,li,ans;
char c;string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	while(n--){
		cin>>li>>c;
		l+=li;while(li--)s+=c;
	}
	for(ll i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i])ans+=1;
	}cout<<ans;
	return 0;
}
