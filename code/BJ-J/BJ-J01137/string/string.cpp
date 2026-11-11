#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n;
char s[1000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long l=0;
    for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=l;j<l+a;j++){
			s[j]=b;
		}
		l+=a;
	}
	long long cnt=0;
	for(long long i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1])cnt++;
	}
	cout<<cnt;
    return 0;
}
