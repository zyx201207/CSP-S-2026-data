#include<bits/stdc++.h>
using namespace std;

 string c1,s1,c2,s2;
 int f=0;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    long long c1n=c1[0]-'0';
    c1n=c1n*10+c1[1]-'0';
    long long c2n=c2[0]-'0';
    c2n=c2n*10+c2[1]-'0';
    if(c1n==c2n) cout << 1;
    else {
        cout << 0;
        cout << 0;
        cout << 0;
        cout << 0;
        return 0;
    }

    long long s1n=s1[0]-'0';
    s1n=s1n*10+s1[1]-'0';
    long long s2n=s2[0]-'0';
    s2n=s2n*10+s2[1]-'0';
    if(s1n==s2n) cout << 1;
    else {
        cout << 0;
        cout << 0;
        cout << 0;
        return 0;
    }

    char sn1=s1[2];
    char sn2=s2[2];
    if((sn1=='A' || sn1=='B' || sn1=='C') && (sn2=='A' || sn2=='B' || sn2=='C')) cout << 1;
    else if((sn1=='D' || sn1=='F') && (sn2=='D' || sn2=='F')) cout << 1;
    else{
        cout << 0;
        cout << 0;
        return 0;

    }

    if((sn1=='A' && sn1=='B') || (sn1=='B' && sn1=='C') || (sn1=='D' && sn1=='F'))cout << 1;
    else cout << 0;
    return 0;
}
