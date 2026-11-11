#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500050],ans,ccj[500050],txj;
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ccj[0]=1;
	for(int i=1;i<=n;i++){
		txj+=(a[i]-a[i-1])*(i-ccj[i-1]);
		if(txj>m){
			int j=ccj[i-1];
			do{
				txj-=a[i]-a[j];
				ccj[i]=++j;
			}while(txj>m&&j<i);
		}else{
			ccj[i]=ccj[i-1];
		}
		ans=max(i-ccj[i]+1,ans);
	}
	cout<<ans;
	return 0;
} 
