#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1 != c2){
        cout<<"0000";
        return 0;
    }
    if(s1[0]!=s2[0] || s1[1]!=s2[1]){
        cout<<"1000";
        return 0;
    }
    if(s1[2]=='F' || s1[2]=='D'){//两个人不可能做一个座
        if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){//这三个都不满足
            cout<<"1100";
            return 0;
        }
    }
    if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){//两个人不可能做一个座
        if(s2[2]=='D' || s2[2]=='F'){//这俩都不满足
            cout<<"1100";
            return 0;
        }
    }
    for(int i=0;i<=1;i++){
        if(s1[2]=='A' && s2[2]=='B'){
            cout<<"1111";
            return 0;
        }else if(s1[2]=='B' && s2[2]=='C'){
            cout<<"1111";
            return 0;
        }else if(s1[2]=='D' && s2[2]=='F'){
            cout<<"1111";
            return 0;
        }
        swap(s1,s2);
    }
    cout<<"1110";
    return 0;
}
/*
05 13A 05 13C
*/
