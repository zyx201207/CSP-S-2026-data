#include<iostream>
#include<string>
#include<map>
using namespace std;
using ll=long long;
#define pf printf
#define f(i,j,k) for(ll i=j;i<=k;i++)
#define F(i,j,k) for(ll i=j;i>=k;i--)
string a1,a2,b1,b2;
map<char,bool>m;
int main(){
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	m['A']=m['B']=m['C']=1,m['D']=m['F']=0,cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){pf("0000");return 0;}
	cout<<1;
	if(a2[0]!=b2[0]||a2[1]!=b2[1]){pf("000");return 0;}
	cout<<1;
	if(m[a2[2]]!=m[b2[2]]){pf("00");return 0;}
	cout<<1<<(a2[2]+1==b2[2]||a2[2]-1==b2[2]||a2[2]=='D'&&b2[2]=='F');
	return 0;
}
