#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],b[10]={0},c[10]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll p=0;p<n;p++){
		for(ll i=p;i<n;i++){
		    if(i==p) b[a[i]]++;
		    else{
		    	bool yes=false;
		    	for(ll j=0;j<i;j++){
			        if(a[j]==a[i]){
			        	yes=true;
			            for(ll k=j+1;k<=i;k++){
			        	    a[k]=0;
		    		    }
    		    		b[a[j]]++;
	    		    }
		        }
		        if(!yes) b[a[i]]++;
    		}
	    }
	    for(ll q=1;q<=m;q++){
	    	if(b[q]!=0) c[q]++; 
		} 
	}
	for(ll i=1;i<=m;i++){
		    cout<<c[i]<<" ";
	    }
	return 0;
}
