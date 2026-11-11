#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d,ans=0;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	else{
		ans+=1000;
		if(b==d){
			ans+=100;
			if((e=='A' && f=='B') || (e=='A' && f=='C') || (e=='B' && f=='A') || (e=='B' && f=='C') || (e=='C' && f=='A') || (e=='C' && f=='B') || (e=='D' && f=='F') || (e=='F' && f=='D')){
				ans+=10;
				if((e=='A' && f=='B') || (e=='B' && f=='A') || (e=='C' && f=='B') || (e=='B' && f=='C') || (e=='D' && f=='F') || (e=='F' && f=='D')){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
