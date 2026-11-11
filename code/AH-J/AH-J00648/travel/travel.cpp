#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	char ra[3],rb[4],xa[3],xb[4];
	cin>>ra>>rb>>xa>>xb;
	if(ra[0]==xa[0]&&ra[1]==xa[1]){
        cout<<'1';
        if(rb[0]==xb[0]&&rb[1]==xb[1]){
            cout<<'1';
            if((rb[2]=='A'&&xb[2]=='B')||(rb[2]=='B'&&xb[2]=='A')||(rb[2]=='A'&&xb[2]=='C')||(rb[2]=='C'&&xb[2]=='A')||(rb[2]=='B'&&xb[2]=='C')||(rb[2]=='C'&&xb[2]=='B')||(rb[2]=='D'&&xb[2]=='F')||(rb[2]=='F'&&xb[2]=='D')){
                cout<<'1';
                if((rb[2]=='A'&&xb[2]=='B')||(rb[2]=='B'&&xb[2]=='A')||(rb[2]=='B'&&xb[2]=='C')||(rb[2]=='C'&&xb[2]=='B')||(rb[2]=='D'&&xb[2]=='F')||(rb[2]=='F'&&xb[2]=='D')){
                    cout<<'1';
                }else cout<<'0';
            }else cout<<'0'<<'0';
        }else cout<<'0'<<'0'<<'0';
	}else cout<<'0'<<'0'<<'0'<<'0';
    return 0;
}
