#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll a[N],b[N];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,k=1;
	cin>>n>>m; 
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(m!=0){
			b[i]=a[i];
			k++;
			m--;
		}
	}
	ll cnt=0;
	for(int i=1;i<k;i++){
		if(i+1==k) cnt+=b[i]&b[i+1];
		else cnt=b[i]&b[i+1];		
	}
	cout<<cnt;
	return 0;
}
