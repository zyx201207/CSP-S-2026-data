#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k[500010],m,q[500010];
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    scanf("%lld",&k[i]);
	}
	sort(k+1,k+n+1,cmp);
	q[1]=k[1];
    for(int i=2;i<=n;i++){
    	q[i]=q[i-1]+k[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll d=0;
			ll z=q[j]-q[i-1];
			d=(j-i+1)*k[j]-z;
			if(d<=m&&maxn<j-i+1) maxn=j-i+1; 
			if(maxn>=n-i+1) break;
		}
	}
	cout<<maxn;
	return 0;
} 
