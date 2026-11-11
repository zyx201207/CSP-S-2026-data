#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a=0,b=0,c=0,d=0;
    int i=s1[2],j=s2[2];
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        a=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            b=1;
            if(int(i)+int(j)==137){
                c=1;
                d=1;
            }
            else if(i<='C'&&j<='C'){
                c=1;
                if(int(i)+int(j)==131||int(i)+int(j)==133){
                    d=1;
                }
            }
        }
    }
    cout<<a<<b<<c<<d<<endl;
    return 0;
}
