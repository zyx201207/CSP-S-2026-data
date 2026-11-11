//liYangJunYi GZ-J00222
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    string k1,k2;
    cin>>c1>>s1>>k1>>k2;
    c2=k1[0]+k1[1];
    s2=k2[0]+k2[1];
    cout<<(c1==s1);
    cout<<(c2==s2);
    if(c2==s2){
        if(k1[2]=='A'){
            if(k2[2]=='B' || k2[2]=='C') cout<<1;
            else cout<<0;
        }
        if(k1[2]=='B'){
            if(k2[2]=='A' || k2[2]=='C') cout<<1;
            else cout<<0;
        }
        if(k1[2]=='C'){
            if(k2[2]=='B' || k2[2]=='A') cout<<1;
            else cout<<0;
        }
        if(k1[2]=='D'){
            if(k2[2]=='F') cout<<1;
            else cout<<0;
        }
        if(k1[2]=='F'){
            if(k2[2]=='D') cout<<1;
            else cout<<0;
        }
    }else cout<<0;
    if((k1[2]-k2[2]==1 || k1[2]-k2[2]==1) || ((k1[2]=='D' && k2[2]=='F') || (k2[2]=='D' && k2[2]=='F')) || (c2-s2==1 || c2-s2==-1)) cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
