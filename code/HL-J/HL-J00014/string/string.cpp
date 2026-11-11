#include<bits/stdc++.h>
using namespace;
int n,a,sum,s[10000005];
char c;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::cin>>n;
	for(int i = 1;i<=n;i++){
		std::cin>>a>>c;
		sum+=a;
		for(int j = 1;j<=a;j++){
			s[j] = c;
		}
	}
	int cnt = 0;
	for(int i = 1;i<=sum/2;i++){
		if(s[i]!=s[sum-i]){
			cnt++;
		}
	}
	std::cout<<cnt;
	return 0;
}