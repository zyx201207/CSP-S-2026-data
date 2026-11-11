#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string sa,sb,ca,cb;
    cin>>sa>>ca>>sb>>cb;
	bool a=(ca[2]=='A'||ca[2]=='B'||ca[2]=='C');
	bool b=(cb[2]=='A'||cb[2]=='B'||cb[2]=='C');
    if(sa==sb){
        cout<<1;
        if(ca[0]==cb[0]&&ca[1]==cb[1]){
            cout<<1;
			if(a==b){
				cout<<1;
				if(a==1&&abs(ca[2]-cb[2])==1){
					cout<<1;
				}
				else if(a==0)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";

    return 0;
}
