#include<bits/stdc++.h>
using namespace std;
#define int long long
int get1(string x){
    return (x[0]-'0')*10+(x[1]-'0');
}
int get3(string x){
    return x[2]-'A'+1;
}
int get2(string x){
    int y=get3(x);
    if(y<=3){
        return 114514;
    }
    return 1919810;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(get1(s1)==get1(s2)){
            cout<<"1";
            if(get2(s1)==get2(s2)){
                cout<<"1";
                if(abs(get3(s1)-get3(s2))==1){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
