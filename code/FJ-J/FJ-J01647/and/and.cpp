#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<string> a;
ll n,m,a2[250007],sl[250007],ls,lm,zgw=0;

string ejj(long long a){
	ll w=0;
	char s[10007];
	while(a){
		if(a%2==1) s[w++]='1';
		else s[w++]='0';
		a/=2;
	}
	for(ll i=w;i<zgw;i++) s[i]='0';
	char ans[10007];
	for(ll i=0;i<zgw;i++)
		ans[zgw-i-1]=s[i];
	return ans;
}


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a2[i];
	sort(a2+1,a2+1+n);
	ll ls=a2[n];
	while(ls) ls/=2,zgw++;
	for(ll i=1;i<=n;i++){
		string ans=ejj(a2[i]);
		a.push_back(ans);
		lm=max(lm,(ll)ans.size());
	}
	
	for(ll j=0;j<zgw;j++)
		for(ll i=0;i<n;i++) 
			if(a[i][j]=='1') sl[j]++;
	
	
	//for(ll i=0;i<n;i++) cout<<a[i]<<endl;
	//for(ll j=0;j<zgw;j++) cout<<sl[j]<<endl;
		
	ll z=(1<<31)-1;
	for(ll j=0;j<zgw;j++){
		//cout<<sl[j]<<" "<<m<<endl;
		if(sl[j]>=m){
			for(ll i=n-1;i>=0,m>0;i--) {
				//cout<<a2[i+1]<<endl;
				if(a[i][j]=='1'){
					//cout<<true<<endl;
					m--,z=z&a2[i+1];
				}
			}
			break;	
		} 
	}
	cout<<z<<endl;
	
	return 0;
}

