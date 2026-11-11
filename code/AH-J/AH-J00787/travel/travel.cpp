#include<bits/stdc++.h>
using namespace std;
long long a1,a2,n,m;
string x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a1>>x>>a2>>y;
    if(a1==a2) cout<<"1";
    else       cout<<"0";
    if(x[0]-'0'==y[0]-'0'&&x[1]-'0'==y[1]-'0'&&a1==a2) cout<<"1";
    else                                               cout<<"0";
    n=x[2]-'A';
    m=y[2]-'A';
    if(x[0]-'0'==y[0]-'0'&&x[1]-'0'==y[1]-'0'&&a1==a2&&((0<=n&&n<=2&&0<=m&&m<=2)||(3<=n&&n<=4&&0<=m&&m<=4))) cout<<"1";
    else cout<<"0";
    if(x[0]-'0'==y[0]-'0'&&x[1]-'0'==y[1]-'0'&&a1==a2&&((0<=n&&n<=2&&0<=m&&m<=2)||(3<=n&&n<=4&&0<=m&&m<=4))&&(n-m==1||m-n==1)) cout<<"1";
    else cout<<"0";
    
    return 0;
}
