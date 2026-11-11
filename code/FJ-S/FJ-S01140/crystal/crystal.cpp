#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l001[555555],l003[555555];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		scanf("%lld",&l001[i]);
	}
	sort(l001,l001+n);
	for(ll h=1;h<n;h++){
		l003[h]=abs(l001[h]-l001[h-1]);
	}
	ll tmp1=0,nb=0,l=1;
	/*
	for(ll l=1;l<n;l++){
		tmp1=0;nb=0;
		for(ll r=l;r<n;r++){
			nb++;
			tmp1+=l003[r]*nb;
			ans=max(ans,nb);
			if(tmp1>m){
				break;
			}
		}
	}
	//*/
	//*
	tmp1=0;nb=0;
	bool b=0;
	for(ll r=l;r<=n;r++){
		if(tmp1>m){
			tmp1-=l001[r]-l001[l-1];
			if(b) nb--;
			else nb-=2;
			l++;
			r--;
			b=1;
			if(l==r){
				nb=0;tmp1=0;
			}	
		}
		else{
			nb++;
			tmp1+=l003[r]*nb;
			b=0;
		}
		ans=max(ans,nb);
	}
	//*/
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

