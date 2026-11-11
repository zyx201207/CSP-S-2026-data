#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N];
unsigned long long sum;
string s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long L=1,R=n;
	while(L<R){
		if(a[L]>a[R]){
			if(s[L]!=s[R])sum+=a[R];
			a[L]-=a[R];
			R--;
		}else{
			if(s[L]!=s[R])sum+=a[L];
			a[R]-=a[L];
			L++;
		}
	}
	
	cout<<sum;
	return 0;
} 
//RP++
//-_- ~~
