#include<bits/stdc++.h>
using ll=long long;
using namespace std;
ll n,m,mx=INT_MIN,mn=INT_MAX,ans=INT_MAX,cnt=INT_MAX,c[32],mex=0,bum,num,q=0,p=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);fclose(0);cin.tie(0);
	cin>>n>>m;
	ll a[n];
	bool b[n],p=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=1;
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
		cnt=cnt&a[i];
		if(ll(pow(2,log2(a[i]+1)))!=a[i]+1){
			p=0;
		}
	}
	if(m==1){
		cout<<mx<<"\n";
	}
	else if(m==n){
		cout<<cnt<<"\n";
	}
	else if(p==1){
	    sort(a,a+n);ans=a[n-1];
		for(int i=n-2;i>=n-m;i--){
			ans=ans&a[i];
		}
		cout<<ans<<"\n";
	}
	else{
		for(int i=33;i>-1;i--){
			bum=(i>>i);
			for(int j=0;j<n;j++){
				if(b[i]==1){
				num=bum&a[j];
				if(num==bum){
					q++;
				}}
			}
			if(q>=m){
				p+=bum;
				for(int j=0;j<n;j++){
				num=bum&a[j];
				if(num!=bum){
					b[i]=0;
				}
			}
			}
		}
		cout<<p<<"\n";}
	return 0;
} 
