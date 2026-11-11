#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool isa,isb,isc,isd;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a == c){
        isa = 1;
        if(b[0] == d[0] && b[1] == d[1]){
            isb = 1;
            if((b[2] <= 'C' && d[2] >= 'D') || ((d[2] <= 'C' && d[2] >= 'D'))){

            }else{
                isc = 1;
                if(d[2] - b[2] == 1 || d[2] - b[2] == -1){
                    isd = 1;
                }
            }
        }
    }
    cout<<isa<<isb<<isc<<isd;
    return 0;
}
