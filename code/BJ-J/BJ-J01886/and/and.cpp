#include<bits/stdc++.h>
#define ll long long
using namespace std;
string totwo(int n){
    string s="00000000";
    int i=7;
    while(n!=0){
        if(n%2==1)
            s[i]='1';
        n/=2;
        i--;
    }
    return s;
}
int toten(string s){
    int n=0,m=1;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1')
            n+=m;
        m*=2;
    }
    return n;
}
int aand(int n1,int m1){
    string n=totwo(n1),m=totwo(m1);
    for(int i=0;i<8;i++)
        if(n[i]!='1'||m[i]!='1')
            n[i]='0';
    return toten(n);
}
int n,m,a,a1[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==1){
        int maxn=0;
        while(n--){
            cin>>a;
            maxn=max(maxn,a);
        }
        cout<<maxn;
        return 0;
    }
    if(m==n){
        int csp;
        cin>>csp;
        for(int i=1;i<n;i++){
            cin>>a;
            csp=aand(csp,a);
        }
        cout<<csp;
        return 0;
    }
    for(int i=0;i<n;i++)
        cin>>a1[i];
    if(m==2){
        int maxn=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(i!=j)
                    maxn=max(maxn,aand(a1[i],a1[j]));
        cout<<maxn;
        return 0;
    }
    sort(a1,a1+n);
    if(m==n-1){
        int csp=a1[1];
        for(int i=2;i<n;i++)
            csp=aand(csp,a1[i]);
        cout<<csp;
        return 0;
    }
    cout<<a1[n-m];
    return 0;
}