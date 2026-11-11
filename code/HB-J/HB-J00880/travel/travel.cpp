#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,cc,ss;
    cin>>c>>s>>cc>>ss;
    string a;
    if(c==cc){
        a+='1';
        if((s[0]==ss[0])&&(s[1]==ss[1])){
            a+='1';
            if(((s[2]<='C')&&(ss[2]<='C'))||((s[2]>'C')&&(ss[2]>'C'))){
                a+='1';
                if((s[2]<='C')&&(ss[2]<='C')){
                    if((s[2]+1==ss[2])||(s[2]-1==ss[2])){
                        a+='1';
                            }else{
                                a+='0';
                        }
                }else{
                     if((s[2]+2==ss[2])||(s[2]-2==ss[2])){
                    a+='1';
                   }else{
                       a+='0';
                   }
                }
        }else{
            a+='0';
            a+='0';

            }
        }else{
            a+='0';
            a+='0';
            a+='0';
}
  }else{
    a+='0';
    a+='0';
    a+='0';
    a+='0';
}

   cout<<a;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
