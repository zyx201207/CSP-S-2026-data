#include<bits/stdc++.h>
using namespace std;
string c1[10],s1[10],c2[10],s2[10];
bool n;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=3;i++){
        cin>>c1[i]>>c2[i];
        if(c1[1]==c2[1]){
            return 1;
        }else return 0;
    }
    for(int i=1;i<=3;i++){
        cin>>s1[i]>>s2[i];
        if(s1[1]==s2[1]){
            return 1;
        }else return 0;
    }
    string m,n;
    m=s1[2];
    n=s2[2];

    cout<<n;
    return 0;
}
