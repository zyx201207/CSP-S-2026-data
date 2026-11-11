#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int f1=0,f2=0,f3=0,f4=0;
    if(c1==c2){
        f1=1;
        string tmp1=s1.substr(0,2);
        string tmp2=s2.substr(0,2);
        if(tmp1==tmp2){
            f2=1;
            char x1=s1[2],x2=s2[2];
            if(x1<='C'&&x2<='C' || x1+x2=='D'+'F'){
                f3=1;
                if(abs(x1-x2)==1){
                        f4=1;
                }
            }
        }
    }
    cout<<f1<<f2<<f3<<f4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
