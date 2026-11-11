#include<bits/stdc++.h>
using namespace std;
long long cnt=0,n,na,sum=0;
char ns,a[200000000000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>na>>ns;
		sum+=na;
		while(na>0){
			a[sum-na]=ns;
			na--;
		}
	}
	for(long long i=0;i<sum/2+1;i++){
		if(a[i]!=a[sum-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
