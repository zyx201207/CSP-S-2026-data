#include<bits/stdc++.h>
using namespace std;	
string str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	long long n,num;
	char c;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>num>>c;
		for(long long j=1;j<=num;j++){
			str+=c;
		}
	}
	long long len=str.length(),cnt=0;
	for(long long i=1;i<=len/2;i++){
		if(str[i-1]!=str[len-i]){
			cnt++;
		}
	}
	printf("%lld",cnt);
	return 0;
}
