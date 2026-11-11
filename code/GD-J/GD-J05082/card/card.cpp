#include<bits/stdc++.h>
using namespace std;
#define intl long long
intl n,m,b;
intl a[10001];
int s(int d,intl c){
	intl n=d*d;
	intl ns=sqrt(c);
	intl w;
	for(int i=1;i<=sqrt(ns)*10;i++){
		w=max(ns*i,c);
	}
	return w;
}
int ra(intl a,intl c){
	intl b=rand()/3;
	return s(a%b,c); 
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m+n;i++){
		b++;
	}
	intl c=b;
	intl j=n+1;
	intl sss=ra(rand(),j)+rand();
	for(int i=1;i<=m;i++) cout<<(sss|(rand()*rand()))%j<<" ";
	return 0;
} 
