#include<bits/stdc++.h>
#define st first
#define nd second
#define inf int(1e9+1)
#define INF int(1E18+1)
using namespace std;
typedef long long L;
typedef unsigned long long UL;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,len=0,ans=0;
	char a;
	string s="";
	cin>>n;
	while(n--){
		cin>>m>>a;
		len+=m;
		while(m--){
			s+=a;
		}
	}
	for(int i=0;i<=len/2;i++){
		if(s[i]!=s[len-i-1]){
			s[len-i-1]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
