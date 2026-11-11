#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
int maxl=INT_MIN;
bool flagA=1; 
bool flagB=1; 
int check(int x){
	x++; 
	while(x){
		if(x%2!=0) return 0;
		x/=2;
	}
	return 1;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(check(a[i])==0) flagA=0;
		if(a[i]!=i-1) flagB=0;
	}
	sort(a+1,a+n+1);
	if(flagB){
		int x,num;
		if(check(n)!=1) x=a[n],num=1;
		else x=a[n-1],num=2;
		for(int i=n-num;i>=1;i){
			if(m==0)break;
			if(check(i)!=1) x^=a[i],m--;
		}
		cout<<x;
		return 0;
	}
	if(flagA){
		cout<<a[n-m+1];
		return 0;
	}
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				maxl=max(maxl,a[i]&a[j]);
		cout<<maxl;
		return 0;
	}
	if(m==n){
		int x=a[1];
		for(int i=2;i<=n;i++)
			x&=a[i];
		cout<<x;
	}
	return 0;
}
/*
1   1 
2	10
3	11
4	100
5	101
6	110
7	111
8	1000
9	1001
10  1010
11  1011
12  1100
13	1101
14	1110
15	1111
16	10000
17	10001
18	10010
19	10011
20  10100
*/

