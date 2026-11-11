#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[300000],s,q1[300000],q2[300000],b[300000];
char c[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		b[i]=b[i-1]+a[i];
	}
	s=b[n];
	ll o=0,f,j;
	f=s%2;
	for(ll i=1;i<=n;i++){
		j=b[i-1]+1;
		for(;j<=b[i];j++){
			if(j<=s/2){
				q1[j]=c[i];
			}
			if(f==1&&j==s/2+1){
				continue;
			}
			if(j>s/2){
				if(q1[s+1-j]!=c[i]){
					o++;
				}
			}
		}
	}
	cout<<o;
	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
//¡¾ÑùÀý3 Êä³ö¡¿
//1 3000000000
