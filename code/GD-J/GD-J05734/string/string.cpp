#include<bits/stdc++.h>
using namespace std;
char s[200005];
long long a[200005]={0};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long cnt=0;
	long long L=1,R=n,x;
	while(L<=R){
		long long maxn=max(a[L],a[R]);
		long long minn=min(a[L],a[R]);
		x=maxn-minn;
		if(s[L]!=s[R]){
			cnt+=minn;
		}
		if(a[L]<a[R]){
			L++;
			a[R]=x;
		}
		else if(a[L]>a[R]){
			R--;
			a[L]=x;
		}
		else{
			L++;
			R--;
		}
	}
	cout<<cnt;
	return 0;
} 
