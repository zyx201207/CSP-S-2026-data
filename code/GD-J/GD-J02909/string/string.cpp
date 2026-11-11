#include<bits/stdc++.h>
using namespace std;
using ll=long long;
char s[100000010];
int main(){
	//¼ì²éfreopenÊÇ·ñ±»×¢ÊÍ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	ll len=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int sum;
		char c;
		cin>>sum>>c;
		while(sum--){
			s[len]=c;
			len++;
		}
	}
	ll ans=0;
	for(ll i=0,j=len-1;i<j;i++,j--){
		if(s[i]!=s[j]) ans++; 
	}
	cout<<ans;
	return 0;
}
