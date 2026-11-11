#include<bits/stdc++.h>
using namespace std;
int ans=0;
string r1,r2,x1,x2;
bool ifqwq(){
    int sum=0;
    if(r2[2]=='D'||r2[2]=='F') sum--;
    else sum++;
    if(x2[2]=='D'||x2[2]=='F') sum--;
    else sum++;
    if(abs(sum)==2) return true;
    else return false;
}
bool ifawa(){
    int a=r2[2]-'A',b=x2[2]-'A';
    if(abs(a-b)==1||r2[2]=='D'&&x2[2]=='F'||r2[2]=='F'&&x2[2]=='D') return true;
    else return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1){
        cout<<1;
        ans++;
    }else{
        cout<<0;
    }
    if(r1==x1&&r2[0]-'0'*10+r2[1]-'0'==x2[0]-'0'*10+x2[1]-'0'){
        cout<<1;
        ans++;
    }else{
        cout<<0;
    }
    if(r1==x1&&r2[0]-'0'*10+r2[1]-'0'==x2[0]-'0'*10+x2[1]-'0'&&ifqwq()==true){
        cout<<1;
        ans++;
    }else cout<<0;
    if(ans==3&&ifawa()==true) cout<<1;
    else cout<<0;
    return 0;
}
