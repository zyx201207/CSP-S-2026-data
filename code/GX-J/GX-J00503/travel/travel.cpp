#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,a1,b,b1;
    scanf("%s%s%s%s",&a,&a1,&b,&b1);
    if(a==b) printf("%s","1");
    else printf("%s","0");
    string cxa="",cxb="";
    char cxa1="",cxb1="";
    for(int i=1;i<=a.size();i++){
        if(i!=b.size()-1){
            cxa+=a1[i];
            cxb+=b1[i];
            }
        else{
            cxa1+=a[i];
            cxb1+=b[i];
        }
    }
    if(cxa==cxb) printf("%s","1");
    else printf("s","0");
    if(cxa1>='A'&&cxa1<='C'&&cxb1>='A'&&cxb1<='c') printf("%s","1");
    else printf("%s","0");
    return 0;


}
