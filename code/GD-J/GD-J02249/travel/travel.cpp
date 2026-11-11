#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool x=false,y=false,z=false,k=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        x=true;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            y=true;
            int w1=s1[2]-'A'+1,w2=s2[2]-'A'+1;
            if(w1>=1&&w2>=1&&w1<=3&&w2<=3||w1>=4&&w2>=4){
                z=true;
                if(abs(w1-w2)==1) k=true;
            }
        }
    }
    cout<<x<<y<<z<<k;
    return 0;
}
