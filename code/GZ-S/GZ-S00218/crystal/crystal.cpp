//GZ-S00218 ³ÂÍþºÀ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll a[N];
bool cmp(ll ab,ll cd){
	return ab<cd;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ll i=1,j=1,cnt=1,cs=0;
	while(j<n){
		j++;
		while(cs+(a[j]-a[j-1])*(j-i)>m){
			i++;
			cs=cs-(a[j-1]-a[i-1]);
		}
		cnt=max(cnt,j-i+1);
		cs=cs+(a[j]-a[j-1])*(j-i);
	}
	cout<<cnt<<endl;
	return 0;
}
