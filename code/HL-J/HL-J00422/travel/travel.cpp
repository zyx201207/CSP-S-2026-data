#include<bits/stdc++.h>
using namespace std;
string g="ABCDF";
bool bingpai(string a,string b){
    int x=1,y=2;
    for(int i=0;i<a.size();i++){
		if(a[i]=='A'||a[i]=='B'||a[i]=='C') x=1;
    	else if(a[i]=='D'||a[i]=='F') x=2;
    }
    for(int i=0;i<b.size();i++){
		if(b[i]=='A'||b[i]=='B'||b[i]=='C') y=1;
    	else if(b[i]=='D'||b[i]=='F') y=2;
    }
    return x==y;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(bingpai(b,d)==1) cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    int n=g.find(b[2]),m=g.find(d[2]);
    if(n==3&&m==4||n==4&&m==3){
        cout<<0;
        return 0;
    }
    if(abs(n-m)==1) cout<<1;
    else cout<<0;
    return 0;
}
