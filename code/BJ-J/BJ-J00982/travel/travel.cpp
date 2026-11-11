#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
   // ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    string a,b,a1,b1;
    cin>>a>>a1>>b>>b1;
    int d=a1[2]-'A',d1=b1[2]-'A';
    string c=a1.substr(0,2),c1=b1.substr(0,2);
   // for(int i=0;i<2;i++) d*=10+int(c[i]-'0");
    //for(int i=0;i<2;i++) d1*=10+int(c1[i]-'0");
    if(a==b){
		cout<<1;
    }else cout<<0;
    if(a==b&&c==c1){
        cout<<1;
    }else cout<<0;

    if(a==b&&c==c1&&((d>=0&&d<=2&&d1>=0&&d1<=2)||(d>=3&&d<=4&&d1>=3&&d1<=4))){
        cout<<1;
    }else cout<<0;
    if(a==b&&c==c1&&((d>=0&&d<=2&&d1>=0&&d1<=2)||(d>=3&&d<=4&&d1>=3&&d1<=4))&&abs(d-d1)==1&&(d!=2&&d1!=3)&&(d!=3&&d1!=2)){
        cout<<1;
    }else cout<<0;

    return 0;
}
