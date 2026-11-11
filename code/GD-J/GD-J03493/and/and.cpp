#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll n,m,a[2005],ans;
bool cmp(ll x,ll y){return x>=y;}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    if(m==1)cout<<a[1];
    if(m==2){
    	for(int i=1;i<=n;i++){
    		for(int j=i;j<=n;j++){
    			ans=max(ans,a[i]&a[j]);
			}
		}
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
	}
	cout<<ans;
	return 0;
}
