#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        int p1=(s1[0]-'0')*10+s1[1]-'0',p2=(s2[0]-'0')*10+s2[1]-'0';
        int l1=s1[2]-'A',l2=s2[2]-'A';
        // cout<<p1<<' '<<p2<<' '<<l1<<' '<<l2<<'\n';
        cout<<(p1==p2?1:0);
        if(p1==p2){
            if(l1<=2&&l2<=2) cout<<1;
            else if(l1>=3&&l2>=3) cout<<1;
            else cout<<0;
        }
        else cout<<0;
        if(p1==p2){
            int mn=min(l1,l2),mx=max(l1,l2);
            if((mx==4&&mn==3)||(mx==1&&mn==0)||(mx==2&&mn==1)) cout<<1;
            else cout<<0;
        }
        else cout<<0;
    }
    else cout<<"0000";
    cout<<'\n';
    return 0;
}