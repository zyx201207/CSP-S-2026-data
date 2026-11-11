#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[20000007];
char c[20000007];
char awa;

int main(){
	freopen("stdin","r",string.in);
	freopen("stdout","w",string.out);
	cin>>n;
	long long sl = 0;
	for(long long i = 1; i <= n; i++){
		cin>>a[i]>>awa;
		for(long long j = 1;j<=a[i];j++){
			c[j+sl] = awa;
		}
		sl += a[i];
	}
	long long l = 1,r = sl;
	long long ans = 0;
	while(l < r){
		if(c[l] != c[r])ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
