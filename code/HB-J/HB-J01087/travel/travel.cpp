#include<bits/stdc++.h>
using namespace std;
int c1,c2,x,y;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    x=s1.size()+1;
    y=s2.size()+1;
    if(c1==c2){
        cout<<1;

        if(s1[x-2]==s2[y-2] && s1[x-1]==s2[y-1]){
            cout<<1;
        }
        else{
            cout<<0;
        }
        if(s1[x]==s2[y]){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
    if((s1[x-2]==s2[y-2] && s1[x-1]==s2[y-1]) && (s1[x]+1==s2[y] || s1[x]-1==s2[y])){
        cout<<1;
    }
    else{
        cout<<0;
    }
return 0;
}
