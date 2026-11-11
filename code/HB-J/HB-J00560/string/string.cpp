#include <bits/stdc++.h>
using namespace std;
const int MOD=2e5+5;
long long t,kl,ans,n;
char c;
string s;
struct node{
	long long num;
	char q;
}a[MOD];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	char d='0';
	while(t--){
		cin>>n>>c;
		if(d==c){
			a[kl].q=c;
			a[kl].num+=n;
		}
		else{
			a[++kl].num+=n;
			a[kl].q=c;
		}
		d=c;
	}
	long long dq=1;
	while(dq!=kl){
		long long iu=min(a[dq].num,a[kl].num);
		if(a[dq].q==a[kl].q){
			a[dq].num-=iu;
			a[kl].num-=iu;
		}
		else{
			a[dq].num-=iu;
			a[kl].num-=iu;
			ans+=iu;
		}
		if(a[kl].num==0 && a[dq].num==0){
			kl--;
			dq++;
		}
		else if(a[kl].num==0){
			kl--;
		}
		else if(a[dq].num==0){
			dq++;
		}
	}
	cout<<ans;
	return 0;
}
