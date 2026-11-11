#include<iostream>
using namespace std;
string c1,s1,c2,s2;
bool ans[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans[1]=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            ans[2]=1;
            int r=s1[2]-'A',x=s2[2]-'A';
            if((r<3&&x<3)||(r>=3&&x>=3)){
                ans[3]=1;
                if(r+1==x||x+1==r) ans[4]=1;
            }
        }
    }
    for(int i=1;i<=4;i++) cout<<ans[i];
    return 0;
}
