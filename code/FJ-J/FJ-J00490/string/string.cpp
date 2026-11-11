#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m[200001],L,sum,Lp,Rp,ans,Ll,Rl;
char s[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>s[i];
		sum+=m[i];
	}
	//cout<<sum<<endl;
	Lp=1;
	Rp=n;
	L=0;
	Rl=m[Rp];
	Ll=m[Lp];
	while(L<sum/2){
		if(Ll<Rl){
			if(s[Lp]!=s[Rp]){
				//cout<<L<<" "<<Ll<<" "<<sum/2<<endl;
				if(L+Ll>sum/2)	ans+=Ll-(L+Ll-sum/2);
				else	ans+=Ll;
			}
			L+=Ll;
			Rl-=Ll;
			Lp++;
			Ll=m[Lp];
		}
		else{
			if(s[Lp]!=s[Rp]){
				//cout<<L<<" "<<Rl<<" "<<sum/2<<endl;
				if(L+Rl>sum/2)	ans+=Rl-(L+Rl-sum/2);
				else	ans+=Rl;
			}
			L+=Rl;
			Ll-=Rl;
			if(Ll==0){
				Lp++;
				Ll=m[Lp];
			}
			Rp--;
			Rl=m[Rp];
		}
	}
	cout<<ans;
	return 0;
}
