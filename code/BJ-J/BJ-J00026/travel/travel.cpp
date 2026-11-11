# include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    string s1,s2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >>a;
    cin >>s1;
    cin >>b;
    cin >>s2;
    if(a==b){
        cout <<1;
    }
    else {
        cout <<0<<0<<0<<0;
        return 0;
    }
    int sum1=0,sum2=0;
    int q,w;
    q=s1[0]-'0';
    w=s1[1]-'0';
    sum1=10*q+w;
    q=s2[0]-'0';
    w=s2[1]-'0';
    sum2=10*q+w;
    if(sum1==sum2){
        cout <<1;
    }
    else {
        cout <<0<<0<<0;
        return 0;
    }
    char e,r;
    e=s1[2];
    r=s2[2];
    if(e=='A'&&r=='B'||e=='A'&&r=='C'||e=='B'&&r=='A'||e=='B'&&r=='C'||e=='C'&&r=='B'||e=='C'&&r=='A'||e=='D'&&r=='F'||e=='F'&&r=='D'){
        cout <<1;
    }
    else {
        cout <<0<<0;
        return 0;
    }
    if(e=='A'&&r=='B'||e=='B'&&r=='A'||e=='B'&&r=='C'||e=='C'&&r=='B'||e=='D'&&r=='F'||e=='F'&&r=='D'){
        cout <<1;
    }
    else {
        cout <<0;
        return 0;
    }
    return 0;
}
