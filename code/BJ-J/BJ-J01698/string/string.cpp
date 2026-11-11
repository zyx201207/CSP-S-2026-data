#include<bits/stdc++.h>
using namespace std;
long long mid1,mid2;
long long n,len,ans;
char s[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>> n;
	if(n == 1){
		cout<< 0;
	}
	for(long long i = 1;i <= n;i ++){
		long long a;char c;
		cin>> a >> c;
		for(long long i = len + 1;i <= len + a;i ++){
			s[i] = c;
		}	
		len += a;
	}
	if(len % 2 == 0){
		mid1 = len / 2 ;
		mid2 = len / 2 + 1;
	}else{
		mid1 = (len + 1) / 2;
		mid2 = (len + 1) / 2;
	}
	for(long long i = 0;i <= mid1 - 1;i ++){
		if(s[mid1-i] != s[mid2+i]){
			ans ++;
		}
	}
	cout<< ans;
	return 0;
}
