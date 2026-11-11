#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    string a=s1.substr(0,2);
    string b=s2.substr(0,2);
    char ch1=s1[2];
    char ch2=s2[2];

    if(c1==c2) cout<<1;
    else cout<<0;

    if(c1==c2&&a==b) cout<<1;
    else cout<<0;

    if(c1==c2&&a==b&&(ch1=='A'&&(ch2=='B'||ch2=='C')||ch1=='B'&&(ch2=='A'||ch2=='C')||ch1=='C'&&(ch2=='A'||ch2=='B'))) cout<<1;
    else cout<<0;

    if(c1==c2&&a==b&&((ch1=='A'&&ch2=='B'||ch1=='B'&&ch2=='A')||(ch1=='B'&&ch2=='C'||ch1=='C'&&ch2=='B')||(ch1=='D'&&ch2=='F'||ch1=='F'&&ch2=='D'))) cout<<1;
    else cout<<0;
    return 0;
}
