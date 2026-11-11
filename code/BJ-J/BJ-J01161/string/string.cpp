#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0,sum=0;
	cin>>n;
	long long s[n+1];
	char s2[n+1];
	for(long long i=1;i<=n;i++){
		cin>>s[i]>>s2[i];
		s[i]+=num;
		num=s[i];
	}
	long long p=1,q=n;
	for(long long i=1;i<=(num+1)/2;i++){
		if(i>s[p])p++;
		if(num-i+1<=s[q-1])q--;
		if(s2[p]!=s2[q])sum++;
	}
	cout<<sum;
	fclose(stdin);fclose(stdout);
	return 0;
}
