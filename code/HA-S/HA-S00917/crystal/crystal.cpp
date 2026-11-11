#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e9+1;
ll a[N];
ll check(int c,int d,int b){
	for(ll i=c;i<d;i++){
		if(a[i+1]>b){
			return i+1;
			break;
		}
	}
}
struct XX{
	ll x,y;
}b[N];
ll cmp(XX a,XX b){
	return a.x<b.x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,maxn=0,tmp,tmp1;
	cin>>n>>m;
	ll c[n];
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]>=0)b[c[i]].x++;
		else b[abs(c[i])].y++;
		ll maxx=maxn;
		if(c[i]>=0){
			maxn=max(maxn,b[c[i]].x);
		}
		else maxn=max(maxn,b[c[i]].y);
		if(maxn!=maxx){
			tmp1=c[i];
		}
	}
	a[0]=0;
	for(int i=1;i<n;i++){
		a[i]=a[i-1]+((c[i]-c[i-1])*(i+1));
	}
	ll ans=maxn;
	if(m==0)cout<<"1";
	else if(maxn!=1){
		for(int i=0;i<n;i++){
		    if(c[i]==tmp1){
		    	tmp=i;
		    	break;
		    }
	    }
	    for(int i=0;i<m;i++){
		    if(c[tmp-1]==c[tmp]){
		    	tmp--;
		    	ans++;
		    	m+=2;
	    	}
	    	else {
		    	c[tmp-1]++;
		    }
	    }
	    cout<<ans;
	}
	else if(maxn==1){
		ans=max(ans,check(0,n,m)+1);
		for(int i=1;i<n;i++){
			a[i-1]=0;
			for(int j=i;j<n;j++){
				a[j]=a[j-1]+((c[j]-c[j-1])*(j-i));
			}
			ans=max(ans,check(i,n,m)+1-i);
		}
		cout<<ans;
	}
	return 0;
}