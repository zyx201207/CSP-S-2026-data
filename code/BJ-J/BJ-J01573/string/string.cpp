#include <bits/stdc++.h>
using namespace std;

int f(string x,string y,int n){
    int cnt=0;
    for(int i=0;i<n;i++)
        if(x[i]!=y[i])
            cnt++;
    return cnt;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //48 score
    int n,cnt=0,rn=0,mid,sand;
    string s,sa,sb,sar,bar;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        s.append(x,c);
        rn+=x;
    }
    if(rn%2==0){
        mid=rn/2;
        sand=mid-1;
        for(int i=0;i<(mid-1);i++)
            sa.append(1,s[i]);
        for(int i=(mid+1);i<rn;i++)
            sb.append(1,s[i]);
    }
    else{
        mid=rn/2;
        sand=mid;
        for(int i=0;i<mid;i++)
            sa.append(1,s[i]);
        for(int i=(mid+1);i<rn;i++)
            sb.append(1,s[i]);
    }
    sar=sa; bar=sb;
    reverse(sar.begin(),sar.end());
    reverse(bar.begin(),bar.end());

    cout<<min(f(sar,sb,sand),f(sa,bar,sand));
}
