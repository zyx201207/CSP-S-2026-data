#include<bits/stdc++.h>
using namespace std;
char m[1000000];
long long p[1000000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	long long n,q=0,s=0;
	string a;
	scanf("%lld",&n);
	for(long long i=0;i<n;i++){
		scanf("%lld%s",&p[i],&m[i]);
		s+=p[i];
		for(int j=0;j<p[i]-1;j++){
			a+=m[i];
		}
	}
	for(int i=0,j=s-1;;i++,j--){
		if(a[j]!=a[i]){
			q++;
		}
		if(j==i) {
			break;
		}
	} 
	cout<<q;
	return 0; 
}
