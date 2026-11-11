#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],n,cnt,tmp;
char c[N];
string t; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		tmp+=a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++)t+=c[i];
	}
	if(tmp%2==1){
		for(long long i=0,j=n;i<n/2,j>n/2;i++,j--){
			if(t[i]!=t[j])cnt++;
		}	
	}
	if(tmp%2==0){
		for(long long i=0,j=n;i<n/2,j>=n/2-1;i++,j--){
			if(t[i]!=t[j])cnt++;
		}
	}
	cout<<cnt;
	return 0;
}





/*
3
2 a
2 b
1 c
aabbc
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
