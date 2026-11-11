#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define foru(a,b,c) for(ll a=b;a<=c;a++)
#define endl "\n"

ll n,a[500005],m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>n>>m;
    foru(i,1,n){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll now=a[1],rq=a[1],ans=1,fst=1;
	foru(i,2,n){
		now+=a[i];
		rq=a[i]*(i-fst+1);
		if(now+m>=rq){
			ans=max(ans,(i-fst+1));
		}else{
			while(fst<i&&now+m<rq){
				now-=a[fst];
				rq-=a[i];
				fst++;
			}
		}
	}
	cout<<ans;
    return 0;
}
