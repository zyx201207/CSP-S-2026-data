#include<bits/stdc++.h>

using namespace std;
long long n,a[1000000],l,c;
char b[1000000];
int fun(int t){
	long long s;
	for(int i=1;i<=n;i++){
		s+=a[i];
		if(s>=t) return i;
	}
}
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
		l+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(i!=l-i+1&&b[fun(i)]!=b[fun(l-i+1)]){
			c++;
		}
	}
	cout << c;
	return 0;
}