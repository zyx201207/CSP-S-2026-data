#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    string p1,p2;
    p1+= s1[0]+s1[1];
    p2+=s2[0]+s2[1];
    char z1 = s1[2],z2 = s2[2];
    if(c1 == c2) {
        cout<<1;
        if(p1 == p2){
            cout<<1;
            if((z1<='C'&&z2<='C') || (z1>='E' && z2>='E')){
                cout<<1;
                if(abs(z1-z2) == 1) cout<<1;
                else cout<<"0";
            }
            else {
            	cout<<"00";
			}
        }
        else{
            cout<<"000";
        }
    }
    else cout<<"0000";

    return 0;
}

