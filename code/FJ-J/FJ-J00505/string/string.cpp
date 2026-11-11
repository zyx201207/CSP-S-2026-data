#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,sum,len,L,R,a[N],b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char ch;long long x;
		cin>>x>>ch;
		if(b[len]==ch) a[len]+=x;
		else{
			a[++len]=x;b[len]=ch;
		}
	}
	R=len;L=1;
	while(L<R){
		if(a[L]>=a[R]){
			a[L]-=a[R];
			if(b[L]!=b[R])sum+=a[R];
			if(a[L]<=0) L++;
			R--;
		}else{
			a[R]-=a[L];
			if(b[L]!=b[R])sum+=a[L];
			L++;
		}
	}
	cout<<sum;
	return 0;
}
