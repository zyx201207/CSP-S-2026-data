#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

typedef long long ll;

ll a[N];
char c[N];
int cnt[N];

int main(){
	
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	
	int T;cin>>T;
	ll te=0;
	for(int i=1;i<=T;i++)
		cin>>a[i]>>c[i];
	
	ll tes=0;
	for(int i=2;i<=T;i++)
	    if(c[i]-'0' != c[i-1]-'0')
	        tes++;
	if(tes==0){
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=1;i<=T;i++){
		for(ll j=te+1;j<=te+a[i]+1;j++)
			cnt[j]=c[i];
		te+=a[i];
	}
	int ans=0;
	if(te%2==0){
		for(ll i=1;i<=te/2;i++){
			int p=cnt[te/2-i];
		    int q=cnt[te/2+1+i];
			if(q!=p) ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	else{
		for(ll i=1;i<=te/2;i++){
			int p=cnt[te/2-i];
		    int q=cnt[te/2+1+i];
			if(q!=p) ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}





