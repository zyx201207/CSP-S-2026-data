#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;
    char z1,z2;
    int c1,c2,p1=0,p2=0;
    cin>>c1>>s1>>c2>>s2;
    int n=s1.size();
    int m=s2.size();
    for(int i=0;i<n;i++){
        if(s1[i]>='0'&&s1[i]<='9'){
            p1=p1*10+int(s1[i])-48;
        }
        else if(s1[i]>='A'&&s1[i]<='Z') z1=s1[i];
    }
    for(int i=0;i<m;i++){
        if(s2[i]>='0'&&s2[i]<='9'){
            p2=p2*10+int(s2[i])-48;
        }
        else if(s2[i]>='A'&&s2[i]<='Z') z2=s2[i];
    }
    if(c1==c2) cout<<1;
    else {
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(p1==p2) cout<<1;
    else {
        cout<<0<<0<<0;
        return 0;
    }
    if((z1=='A'&&(z2=='B'||z2=='C'))||(z1=='B'&&(z2=='A'||z2=='C'))||(z1=='C'&&(z2=='A'||z2=='B'))||(z1=='D'&&(z2=='F'))||(z1=='F'&&(z2=='D'))) cout<<1;
    else{
        cout<<0<<0;
        return 0;
    }
    if((z1=='A'&&z2=='B')||(z1=='B'&&(z2=='A'||z2=='C'))||(z1=='C'&&(z2=='B'))||(z1=='D'&&z2=='F')||(z1=='F'&&z2=='D')) cout<<1;
    else cout<<0;
    //cout<<p1<<z1<<" "<<p2<<z2;
    return 0;
}
