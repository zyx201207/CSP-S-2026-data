#include<bits/stdc++.h>
#define ll long long
#define FOR(x,y,z) for(int x=y;x<=z;x++)
#define ROF(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
const int N=2e5+5;
struct node{
	ll s;
	char c;
}a[N];
ll n,m,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	m=n;
	FOR(i,1,n)cin>>a[i].s>>a[i].c;
	FOR(i,1,n){
		while(a[i].s){
			if(a[i].s>=a[m].s){
				if(a[i].c!=a[m].c)ans+=a[m].s;
				a[i].s-=a[m].s;
				a[m].s=0;
				m--;
			}else{
				if(a[i].c!=a[m].c)ans+=a[i].s;
				a[m].s-=a[i].s;
				a[i].s=0;
			}
		}
	}
	cout<<ans;
	return 0;
}

