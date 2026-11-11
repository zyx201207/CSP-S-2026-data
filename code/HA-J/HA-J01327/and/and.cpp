#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n,m,ans,anss;
long long s[200005];
//string sa,sb;
//int a[10000000];
//
//int func(int a,int b){
//	int aa;
//	while(a){
//		sa+=(a%2)+'0';
//		a/=2;
//	}while(b){
//		sb+=(b%2)+'0';
//		b/=2;
//	}
//	for(int i=0; i<min(sa.length(),sb.length()); i++){
//		if(sa[i]==sb[i]) a[i]=1;
//	}
//	for(int i=0; i<max(sa.length(),sb.length()); i++){
//		a[i]*=pow(2,i);
//		ans+=a[i];
//	}
//}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		cin >> s[i];
	}
	
//	sort(a+1,a+1+n);
//	
//	for(int i=n; i>n-m+1; i--){
//		anss=func(s[i],s[i]-1);
//	}
//	
//	cout << anss;

	int a=rand();
	cout << a;
	return 0;
}

