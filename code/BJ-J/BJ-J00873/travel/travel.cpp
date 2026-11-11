#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,y,cnt1,cnt2;
string xt,yt;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> x >> xt >> y >> yt;
    if(x!=y){
        cout << "0000";
        return 0;
    }else{
        cout << "1";
    }
    int i=0;
    while(xt[i]>='0'&&xt[i]<='9'){
        cnt1*=10;
        cnt1+=xt[i]-'0';
        i++;
    }
    char xq=xt[i];
    i=0;
    while(yt[i]>='0'&&yt[i]<='9'){
        cnt2*=10;
        cnt2+=yt[i]-'0';
        i++;
    }
    char yq=yt[i];
    i=0;
   // cout << cnt1 << " " << xq << " " << cnt2 << " " << yq << "\n";
    if(cnt1==cnt2){
        cout << 1;
    }else{
        cout << "000";return 0;
    }
    if(((xq=='A'||xq=='B'||xq=='C')&&(yq=='D'||yq=='F'))||((yq=='A'||yq=='B'||yq=='C')&&(xq=='D'||xq=='F'))){
        cout << "00";return 0;
    }else{
        cout << 1;
    }
    if((xq=='A'&&yq=='B')||(xq=='B'&&yq=='C')||(xq=='D'&&yq=='F')||(xq=='B'&&yq=='A')||(xq=='C'&&yq=='B')||(xq=='F'&&yq=='D')){
        cout  << 1;
    }else cout << "0";
    return 0;
}

