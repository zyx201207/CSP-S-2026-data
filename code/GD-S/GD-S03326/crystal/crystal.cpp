#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define gc getchar 
#define mn 500005
#define F(_,x,y) for(int _=x;_<=y;_++)
using namespace std;
int n,l=1,r=1,as;ll m,a[mn],s[mn];
ll rd(){ll x=0;char c=gc();int f=(c=='-');while(c<48)c=gc();
	while(c>47)x=x*10+c-48,c=gc();return x*(f?(-1):1);
}int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	n=rd();m=rd();F(_,1,n)a[_]=rd();sort(a+1,a+n+1);F(_,1,n)s[_]=s[_-1]+a[_];
	while(r<=n){r++;while(1ll*(r-l+1)*a[r]-s[r]+s[l-1]>m)l++;as=max(as,r-l+1);}
	cout<<as;return 0;
}
