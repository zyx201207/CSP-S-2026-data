#include <bits/stdc++.h>
using namespace std;

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    //cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2<<endl;
    if (c1!=c2)
        printf("0000");
    else if (c1==c2){
        printf("1");
        //cout<<s1.substr(0,2)<<endl;
        //cout<<s2.substr(0,2)<<endl;
        if (s1.substr(0,2)==s2.substr(0,2)){
            printf("1");
            if (s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
                printf("1");
                if (abs(s2[2]-s1[2])<=1&&s2[2]<='C'||s2[2]>='D')
                    printf("1");
                else printf("0");
            }else printf("00");
        }else printf("000");
    }
    return false;
}
