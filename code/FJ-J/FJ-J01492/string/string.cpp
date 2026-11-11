#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct ac{
	ll a;
	char c;
};
ll n;
ac A[20007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll ans=0,sum=0;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>A[i].a>>A[i].c;
		sum+=A[i].a;
	}
	ll k=0,i=0;
	while(k<sum){
		k+=A[i].a;
		i++;
	}
	ll l=0,r=n-1,lsum=0,rsum=0;
	for(ll j=0;j<sum/2;j++){
		if(A[l].c!=A[r].c){
			ans++;
		}
		if(j+1==lsum){
			lsum+=A[l].a;
			l++;
		}
		if(sum/2-j==rsum){
			rsum+=A[r].a;
			r--;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
