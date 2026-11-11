#include<bits/stdc++.h>
#define ll long long
using namespace std;
string S="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a;
	char c;
	ll ans=0;
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			S+=c; 
		}
	}
	int len=S.size();
	for(int i=0;i<len/2;i++){
		if(S[i]!=S[len-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
