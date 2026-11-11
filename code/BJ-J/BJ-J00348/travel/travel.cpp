#include<bits/stdc++.h>
using namespace std;
bool check(string x, string y){
    if(x=="01"){
        if(y=="02"){
            return true;
        }
    }
    else if(x=="02"){
        if(y=="01"||y=="03"){
            return true;
        }
    }
    else if(x=="03"){
        if(y=="02"||y=="04"){
            return true;
        }
    }
    else if(x=="04"){
        if(y=="03"||y=="05"){
            return true;
        }
    }
    else if(x=="05"){
        if(y=="04"||y=="06"){
            return true;
        }
    }
    else if(x=="06"){
        if(y=="05"||y=="07"){
            return true;
        }
    }
    else if(x=="07"){
        if(y=="06"||y=="08"){
            return true;
        }
    }
    else if(x=="08"){
        if(y=="07"||y=="09"){
            return true;
        }
    }
    else if(x=="09"){
        if(y=="08"||y=="10"){
            return true;
        }
    }
    else if(x=="10"){
        if(y=="09"||y=="11"){
            return true;
        }
    }
    else if(x=="11"){
        if(y=="10"||y=="12"){
            return true;
        }
    }
    else if(x=="12"){
        if(y=="11"||y=="13"){
            return true;
        }
    }
    else if(x=="13"){
        if(y=="12"||y=="14"){
            return true;
        }
    }
    else if(x=="14"){
        if(y=="13"||y=="15"){
            return true;
        }
    }
    else if(x=="15"){
        if(y=="14"||y=="16"){
            return true;
        }
    }
    else if(x=="16"){
        if(y=="15"||y=="17"){
            return true;
        }
    }
    else if(x=="17"){
        if(y=="16"||y=="18"){
            return true;
        }
    }
    else if(x=="18"){
        if(y=="17"){
            return true;
        }
    }
    return false;
}
void solve(){
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout <<"0000";
        return;
    }
    else{
        cout<<"1";
    }
    string x,y;
    x=s1[0]+s1[1];
    y=s2[0]+s2[1];
    int a=s1[2],b=s2[2];
    if(x == y){
        cout <<"1";
        if(s1[2]>='D'&&s2[2]>='D' || s1[2]<='C'&&s2[2]<='C'){
            cout << "1";
        }
        else cout << "0";
    }
    else {
        cout << "00";
    }
    if((s1[2]>='D'&&s2[2]>='D' || s1[2]<='C'&&s2[2]<='C')&&((s1[2]==s2[2]&&check(x, y))||(x==y&&(a+1==b||a-1==b)))){
        cout << 1;
    }
    else cout <<"0";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
