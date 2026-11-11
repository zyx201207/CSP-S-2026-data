#include <bits/stdc++.h>
using namespace std;
int n,s[200005];
string st[200005],s1,s2;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		cin >> s[i] >> st[i];
	}
	for(int i=1,j=n;i < j;){
		int cnt = min(s[i],s[j]);
		if(st[i] != st[j]){
			sum += cnt;
		}
		s[i] -= cnt;
		s[j] -= cnt;
		if(s[i] == 0){
			i++;
		}
		if(s[j] == 0){
			j--;
		}
	}
	printf("%lld",sum);
	return 0;
}

