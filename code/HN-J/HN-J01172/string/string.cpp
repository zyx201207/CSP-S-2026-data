#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char s[200005];
bool cmp(long long qwert,long long b){
	return qwert>b;
}//´óµ½Ð¡£¬µ¹Ðò 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long cg,l=1,r=n,ans=0;
	while(l<r){
		cg=min(a[r],a[l]);
		if(s[l]!=s[r]){
			ans+=cg;
		}
		a[r]-=cg,a[l]-=cg;
		if(a[r]==0){
			r--;
		}
		if(a[l]==0){
			l++;
		}
	}
	cout<<ans;
	return 0;
}
