#include<bits/stdc++.h>
using namespace std;

char c1[5],s1[5],c2[5],s2[5];
int r[5],x[5];
int ans[4];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    r[0]=(c1[0]-'0')*10+(c1[1]-'0');
    x[0]=(c2[0]-'0')*10+(c2[1]-'0');
    if(r[0]==x[0]) ans[0]=1;
    r[1]=(s1[0]-'0')*10+(s1[1]-'0');
    x[1]=(s2[0]-'0')*10+(s2[1]-'0');
    if( (r[1] == x[1]) && ans[0]) ans[1]=1;
    r[2]=s1[2]-'A'+1;
    x[2]=s2[2]-'A'+1;
    bool f1=0,f2=0;
    if((r[2]>=4 && r[2]<=6) && (x[2]>=4 && x[2]<=6) && ans[1]){
            ans[2]=1;
            f1=1;
    }
    if((r[2]>=1 && r[2]<=3) && (x[2]>=1 && x[2]<=3) && ans[1]){
            ans[2]=1;
            f2=1;
    }
    if(f1) ans[3]=1;
    if(f2 && (r[2]-x[2]==1 || x[2]-r[2]==1)) ans[3]=1;
    cout<<ans[0]<<ans[1]<<ans[2]<<ans[3]<<endl;
    return 0;
}
