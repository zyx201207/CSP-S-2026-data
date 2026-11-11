#include<bits/stdc++.h>
#define ll long long
#define FR(a,b,c) for(ll a=b;a<=c;++a)
#define RF(a,b,c) for(ll a=b;a>=c;--a)
using namespace std;
const int N=5e5+7;
ll n,m,a[N],p[N],l[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	FR(i,1,n)cin>>a[i];
	if(n>500&&m>200){
		FR(i,2,n){
			if(a[i-1]!=a[i])cout<<i-1<<" ";
			if(i==n){
				cout<<n;
			}
		}
	}else{
		FR(i,1,n){
			ll s=0;
			FR(k,i,n){
				FR(j,1,s){
					if(l[j]==a[k]){
						s=j-1;
						break;
					}
				}
				l[++s]=a[k];
			}
			FR(k,1,s){
				p[l[k]]++;
			}
		}
		FR(i,1,m){
			cout<<p[i];
			if(i!=m)cout<<" ";
		}
	}

	return 0;
}
