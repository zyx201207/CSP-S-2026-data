#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],pre[200005],mid,l,ll1,r,rr,flag=1,ans,t;//l,r组数,ll1,rr个数 
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		pre[i]=pre[i-1]+a[i];
	}
	mid=pre[n]/2+(pre[n]%2?1:0);
	for(int i=1;i<=n;i++){
		if(pre[i]<mid&&pre[i+1]>=mid){
			t=i+1;
			break;
		}
	}
//	cout<<mid<<" "<<t<<'\n'; 
	if(pre[t]==mid){
		l=t; ll1=a[t]-(pre[n]%2?1:0); r=t+1; rr=1;
		if(pre[n]%2&&ll1==0){
			l--;
			ll1=a[t-1];
		}
	}
	else{
		l=t; ll1=mid-pre[t]+a[t]-(pre[n]%2?1:0); r=l; rr=ll1+1+(pre[n]%2?1:0);
		if(pre[n]%2&&ll1==0){
			l--;
			ll1=a[t-1];
		}
	}
	while(flag){
		if(ll1<a[r]-rr+1){
			if(b[l]!=b[r]) ans+=ll1;
			rr+=ll1;
			l--;
			ll1=a[l];
		}
		else if(ll1==a[r]-rr+1){
			if(b[l]!=b[r]) ans+=ll1;
			l--; r++;
			ll1=a[l]; rr=1;
		}
		else{
			if(b[l]!=b[r]) ans+=a[r]-rr+1;
			ll1-=a[r]-rr+1;
			r++;
			rr=1;
		}
		if(l<1||r>n) flag=0;
	}
	cout<<ans;
	return 0;
}

