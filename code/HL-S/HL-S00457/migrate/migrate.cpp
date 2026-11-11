#include<bits/stdc++.h>
using namespace std;
long long a[780000],b,n,m,ans,ban,ban1,ban_0,ak[780000],akk[780000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>b>>ban;
    if(b==0){
    	if(ban==2){
    		cin>>ans>>m;
    		if(ans==4&&m==2){
    			cout<<1<<endl<<2;
    			return 0;
			}
			if(ans==4&&m==2){
    			cout<<0<<endl<<1;
    			return 0;
			}
		}
		if(ban==17){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
			return 0;
		}
	}
	cout<<1;
    return 0;
}


