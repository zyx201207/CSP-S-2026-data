#include<bits/stdc++.h>
using namespace std;
long long a[500005],t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long k=1;k<=n;k++){
		string s;
		for(long long i=k;i<=n;i++){
			char c=char(a[i]+48);
			if(s.find(c)==string::npos){
				s+=c;
			}
			else{
				s.erase(s.find(c));
				s+=c;
			}
		}
		for(long long i=0;i<s.size();i++){
			t[int(s[i]-48)]++;
		}
	}
	for(long long i=1;i<=m;i++){
		printf("%lld ",t[i]);
	}
	return 0;
}
