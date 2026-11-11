#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,ans;
string s,s1;
int ne[N];//当前到i的位置时是否匹配 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		ll m;
		char a,b;
		scanf("%lld%c%c",&m,&b,&a);
		for(int j=1;j<=m;j++){
			s+=a;
		}
	}
	s=' '+s;
	int len=s.size()-1;
	int k=1;
	for(int i=len;i>=1;i--){
		s1[k++]=s[i];
	}
	for(int i=1;i<=len;i++){
		if(s1[i]!=s[i]){
			s[len-i+1]=s[i];
			ans++;
		}
	}
	cout<<s;
	printf("\n%lld",ans);
	return 0;
}
