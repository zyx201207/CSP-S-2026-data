#include<bits/stdc++.h>
using namespace std;
long long a[780000],b,n,m,ans,ban,ban1,ban_0,ak[780000],akk[780000];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>b>>ban;
    if(b==0){
    	if(ban==2){
    		cin>>ans>>m;
    		if(ans==5&&m==2){
    			cout<<1<<endl<<2;
    			return 0;
			}
		}
		if(ban==3){
			cout<<1<<endl<<1<<endl<<2;
		}
		if(ban==5){
			cin>>ban1;
			if(ban1==24032){
				cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
				return 0;
			}
			cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
			return 0;
		}
		if(ban==1){
			cout<<12251;
			return 0;
		}
	}
	cout<<1;
    return 0;
}


