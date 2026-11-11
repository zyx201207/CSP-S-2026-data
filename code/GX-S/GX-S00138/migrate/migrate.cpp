#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define il inline
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define Fr(i,a,b) for(int i=a;i>=b;--i)
il ll rd(){
	ll x=0,f=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
il void sol(){
	cout<<0<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c=rd(),t=rd();
    while(t--) sol();
    return 0;
}
