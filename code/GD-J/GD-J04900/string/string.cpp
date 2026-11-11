#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m,cnt=0;
char h;
char s[100000005];
long long a[100000005];
int main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		cin>>a[i]>>h;
		cnt+=a[i];
		for(int j= 0;j<a[i];j++){
			s[j]+=h;
		}
	}
	int sum = 0;
	for(int i = 0;i<cnt/2;i++){
		if(s[i]!=s[cnt-1-i]) sum++;
	}
	printf("%d",sum);
	return 0;
}
