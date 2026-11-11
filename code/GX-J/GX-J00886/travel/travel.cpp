#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c,ca,a[4]={0,0,0,0};
    string s,sa;
    cin>>c>>s>>ca>>sa;
    if(c==ca){
        a[0]=1;
        if(s[0]+s[1]==sa[0]+sa[1]){
            a[1]=1;
            if(s[2]>=65 && s[2]<=67 && sa[2]>= 65 && sa[2]<= 67){
                a[2]=1;
            }
            else if(s[2]>=68 && s[2]<=69 && sa[2]>= 68 && sa[2]<= 69){
                a[2]=1;
            }
            if(a[2]==1 && abs(s[2]-sa[2])==1)a[3]=1;
        }
    }
    for(int i=0;i<4;i++)cout<<a[i];
    return 0;
}
