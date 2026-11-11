#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m;
int n;
ll a[500005];

int ans[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) ans[i] = 1;
	
	for(int i=1;i<=n-1;i++){
    	for(int j=i+1;j<=n;j++){
    		int t;
    		if(a[i]<a[j]){
    			t=a[i];
    			a[i] = a[j];
    			a[j] = t;
			}
		}
	}

	int n1 = (n-1);
	int cnt=1;
	while(n1--){
	ll sum = 0;
	for(int i=1+cnt;i<=n;i++){
		ll big = a[cnt];
		sum+=(big-a[i]);
		if(sum>m){
		    break;	
		} else{
		    ans[cnt]++;	
		}
	}
	cnt++;
    }
	int MAXN = 0;
	for(int i=1;i<=n;i++) {
	    MAXN=max(MAXN,ans[i]);
	}
    cout<<MAXN;

	return 0;
} 
