#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
long long a[maxn],pay[maxn],n,m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	pay[1]=0;
    for(int i=2;i<=n;i++){	
	    pay[i]=pay[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=n;i>=1;i--){
		if(m>=pay[i]){
			cout<<i;
			return 0;
		}
	}
    return 0; 
}
