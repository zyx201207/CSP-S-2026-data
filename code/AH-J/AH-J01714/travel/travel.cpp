///小X和小R能不能去死啊！！！
#include<bits/stdc++.h>
using namespace std;
string s1,s2;
short c1,c2;
bool _,__,___,____;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        _=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            __=1;
            if(s1[2]<='C'&&s2[2]<='C'){
                ___=1;
                if(abs(s1[2]-s2[2])==1)____=1;
            }else if(s1[2]>='D'&&s2[2]>='D'){
                ___=____=1;
            }
        }
    }
    cout<<_<<__<<___<<____;
    fclose(stdin),fclose(stdout);
    return 0;
}
///求AC！！！求AC！！！求AC！！！
///求AC！！！求AC！！！求AC！！！
///求AC！！！求AC！！！求AC！！！
