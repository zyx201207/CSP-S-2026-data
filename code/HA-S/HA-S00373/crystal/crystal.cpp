#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans=0,sum=1,lid=0;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ll tmp=m;
	for(int i=2;i<=n;i++){
		if(a[1]-a[i]<=tmp){
			tmp-=a[1]-a[i];
			lid=i;
			sum++;
		}else{
			break;
		}
	}
	ans=sum;
	ll t2=a[1],id=0;
	for(int i=2;i<=n;i++){
		tmp+=(lid-i+1)*(t2-a[i]);
		sum=lid-i+1;
		id=lid;
		for(int j=id+1;j<=n;j++){
			if(a[i]-a[j]<=tmp){
				tmp-=a[i]-a[j];
				lid=j;
				sum++;
			}else{
				break;
			}
		}
		t2=a[i];
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9

*/
