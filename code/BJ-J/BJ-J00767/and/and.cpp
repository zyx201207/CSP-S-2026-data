#include<bits/stdc++.h>
using namespace std;
string erjinzhi(int x){
    string q;
    int a;
    for(int i=2^(x/2);i>=1;i/=2){
        if(i<=x) a=i;
    }
    for(int i=a;i>=1;i/=2){
        if(x>=i){
            q+='1';
            x-=i;
        }else q+='0';
    }
    return q;
}
string anweiyu(string a,string b){
    string p;
    for(int i=1;i<=max(a.size(),b.size());i++){
        if(a[i]==b[i]) p[i]==1;
        else p[i]==0;
    }
    return p;
}
string s;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    const int N=2e5+10;
    int n,m,a[N],a1[N],sum=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        a1[n-i]=a[i];
    }
    for(int i=1;i<=m;i++){
        s=anweiyu(erjinzhi(a1[i]),s);
    }
    for(int i=1;i<=s.size();i++){
        if(s[i]==1) sum+=2^i;
    }
    cout << sum;
    return 0;
}
