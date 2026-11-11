#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1 == c2);

    cout<<((c1 == c2)&&(s1.substr(0,s1.size()-1) == s2.substr(0,s2.size()-1)));
    if((c1 == c2)&&(s1.substr(0,s1.size()-1) == s2.substr(0,s2.size()-1))){
        char t1 = s1[2];
        char t2 = s2[2];
        bool a1 = t1 <= 'C';
        bool a2 = t2 <= 'C';
        if(a1 == a2){
                cout<<1;
            if(!a1){
                cout<<1;
            }else{
                int k = abs((int)t1 - (int)t2);
                if(k <= 1)
                    cout<<1;
                else
                    cout<<0;
            }

        }else{
            cout<<"00";

        }


    }  else{
    cout<<"00";
    }
    return 0;

}
