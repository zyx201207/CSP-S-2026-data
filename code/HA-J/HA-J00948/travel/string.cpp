#include <bits/stdc++.h>
using namespace std;
long long n,s;
int a[200005],b[200005],maxx;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for (int i=1;i<=n;i++){
		cin >>a[i]>>c[i];
		s+=a[i];
		b[c[i]]+=a[i];	
	}
	if (n==1){
		cout <<0;
		return 0;
	}
	for (int i=1;i<=n;i++){
		maxx=max(maxx,b[c[i]]);
	}
	if (maxx>s/2){
		cout <<maxx-s;
		return 0;
	}
	if (maxx==s/2){
		cout <<s/2;
		return 0;
	}
	else{
		cout <<maxx;
		return 0;
	}
	return 0;
} 
