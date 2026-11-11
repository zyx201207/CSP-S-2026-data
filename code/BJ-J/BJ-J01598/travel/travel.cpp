#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
#define pb emplace_back

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    int x1=s1[1]-'0';
    int x2=s2[1]-'0';
    if(s1[0]=='1') x1+=10;
    if(s2[0]=='1') x2+=10;
    if(x1!=x2){
        cout<<"1000";
        return 0;
    }
    bool f1=0,f2=0;
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') f1=1;
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') f2=1;
    if(f1^f2){
        cout<<"1100";
        return 0;
    }
    if(f1){
        if(s1[2]=='B'||s2[2]=='B'){
            cout<<"1111";
        }else{
            cout<<"1110";
        }
        return 0;
    }
    cout<<"1111";
    return 0;
}
