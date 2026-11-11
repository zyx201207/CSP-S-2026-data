#include <bits/stdc++.h>
using namespace std;
string cc1,ss1,cc2,ss2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>cc1>>ss1>>cc2>>ss2;
    if(cc1!=cc2){
        cout<<"0000";
    }
    else{
        cout<<"1";
        int rp=0,sp=0;
        for(int i=0;i<2;i++){
            rp=rp*10+ss1[i]-'0';
            sp=sp*10+ss2[i]-'0';
        }
        if(rp==sp)
            cout<<"1";
        else{
            cout<<"000";
            return 0;
        }
        char rz=ss1[2],sz=ss2[2];
        if((rz=='A'&&sz=='B')||(rz=='A'&&sz=='C')||(rz=='B'&&sz=='A')||(rz=='B'&&sz=='C')||(rz=='C'&&sz=='A')||(rz=='C'&&sz=='B')||(rz=='D'&&sz=='F')||(rz=='F'&&sz=='D')){
            cout<<"1";
        }
        else{
            cout<<"00";
            return 0;
        }
        if((rz=='A'&&sz=='B')||(rz=='B'&&sz=='A')||(rz=='B'&&sz=='C')||(rz=='C'&&sz=='B')||(rz=='D'&&sz=='F')||(rz=='F'&&sz=='D')){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
	return 0;
}
