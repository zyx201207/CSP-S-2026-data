#include<bits/stdc++.h>
using namespace std;
string a,aa,b,bb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>aa>>b>>bb;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    else if(aa[0]!=bb[0]||aa[1]!=bb[1]){
        cout<<"1000";
        return 0;
    }
    else if(aa[2]=='A'&&bb[2]=='B'){
        cout<<"1111";
        return 0;
    }
    else if(aa[2]=='B'&&bb[2]=='A'){
        cout<<"1111";
        return 0;
    }
    else if(aa[2]=='C'&&bb[2]=='B'){
        cout<<"1111";
        return 0;
    }
    else if(aa[2]=='B'&&bb[2]=='C'){
        cout<<"1111";
        return 0;
    }
    else if(aa[2]=='F'&&bb[2]=='D'){
        cout<<"1111";
        return 0;
    }
    else if(aa[2]=='D'&&bb[2]=='F'){
        cout<<"1111";
        return 0;
    }
    else if(aa[2]=='A'||aa[2]=='B'||aa[2]=='C'){
        if(bb[2]=='A'||bb[2]=='B'||bb[2]=='C'){
            cout<<"1110";
            return 0;
        }
    }
    else if(aa[2]=='D'||aa[2]=='F'){
        if(bb[2]=='F'||bb[2]=='D'){
            cout<<"1110";
            return 0;
        }
    }
    cout<<"1100";
    return 0;
}
