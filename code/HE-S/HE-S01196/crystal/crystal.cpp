#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
struct cry{
	long long q;
	long long s;
};
cry a[MAXN];

bool cmp(cry x,cry y){
	return x.q <y.q ;
}
bool cnp(cry x, cry y){
	return x.s <y.s ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].q ;
	}
	sort (a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		a[i].s =a[i].q -a[i-1].q ;
	}
	sort(a+1,a+1+n,cnp);
	int ans=0;
    for(int i=1;m>=a[i].s;i++){
    	m-=abs(a[i].s );
    	ans++;
    	if(a[i].s==0){
    		ans++;
		}
	}
	cout<<ans;
	return 0;
}
