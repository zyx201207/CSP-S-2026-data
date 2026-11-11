#include<bits/stdc++.h>
using namespace std;
vector <int> x;
string a,b;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
    x.push_back( (c1==c2)? 1:0);

    a+=s1[0]+s1[1];
    b+=s2[0]+s2[1];

    x.push_back( (a==b)? 1:0);
    char c=s1[2];char d=s2[2];
    x.push_back( ( ((c=='A' || c=='B' || c=='C')&&(d=='A' || d=='B' || d=='C')) || ((c=='D' || c=='F')&&(d=='D' || d=='F')) ) ? 1:0 );
    x.push_back( (abs( (int)c- (int)d)==1) ? 1:0);
    for (int i=0;i<4;i++){
        if (x[i]==0) for (int j=i;j<4;j++) x[j]=0;
    }
    for (int i=0;i<4;i++) cout<<x[i];cout<<endl;
    return 0;
}
