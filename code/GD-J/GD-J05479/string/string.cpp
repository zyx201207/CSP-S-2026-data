#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=200009;

ll a[N],l[N],r[N],n,L=0,k,len=0;
char c[N],lc[N],rc[N];

ll min(ll a,ll b){ return a>b?b:a;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	L/=2;
	len=0;
	k=0;
	while(len<L){
		lc[k]=c[k];
		ll x=min(a[k],L-len);
		l[k]=x;
		len+=x;
		    //cout<<l[k]<<lc[k]<<'/';
		k++;
	}
	len=0;
	k=0;
	while(len<L){
		rc[k]=c[n-1-k];
		ll x=min(a[n-1-k],L-len);
		r[k]=x;
		len+=x;
		    //cout<<r[k]<<rc[k]<<'/';
		k++;
	}
	

	
	ll lw=l[0],rw=r[0],lp=0,rp=0,cnt=0,res=0;
	k=0;
	while(k<L){
		if(lw>rw){
			if(lc[lp]!=rc[rp]) res+=rw-k;
			rp++;
			k=rw;
			rw+=r[rp];
		}
		if(lw<rw){
			if(lc[lp]!=rc[rp]) res+=lw-k;
			lp++;
			k=lw;
			lw+=l[lp];
		}
		if(lw==rw){
			if(lc[lp]!=rc[rp]) res+=rw-k;
			lp++;
			rp++;
			k=rw;
			if(k>=L) break;
			lw+=l[lp];
			rw+=r[rp];
		}
	}
	cout<<res;
}

