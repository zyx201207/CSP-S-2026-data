#include <bits/stdc++.h>
using namespace std;
string sr1,sr2,sx1,sx2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>sr1>>sr2>>sx1>>sx2;
    if(sr1==sx1){
        cout<<"1";
        int f=1;
    for(int i=0;i<sr2.size()-1;i++){
        if(sr2[i]!=sx2[i]){
            f=0;
        }
    }
    if(f){
            cout<<"1";
            if(sr2[sr2.size()-1]<='C'&&sx2[sx2.size()-1]<='C'||sr2[sr2.size()-1]>='D'&&sx2[sx2.size()-1]>='D'){
                cout<<"1";
                if(abs(sr2[sr2.size()-1]-sx2[sx2.size()-1])==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
    }
    }else{
        cout<<"0000";
    }

    return 0;
}
