#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ma=-99999,sum1,z1=1;
string s[200010];
string aaa(long long x){
    string y,y1;
    int z;
    while(x>=1){
    z=x%2;
    if(z==0) y+='0';
    else y+='1';
    x=x/2;
    }
    return y;
}
long long and1(string x,string y){
    long long z=1,sum=0;
    for(int i=0;i<max(x.size(),y.size());i++){
        if(x[i]=='1'&&y[i]=='1'){
            sum+=z;
        }
        z=z*2;
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=aaa(a[i]);
    }
    if(m==1){
    for(int i=1;i<=n;i++){
    ma=max(ma,a[i]);
    }
    cout<<ma;
    return 0;
    }
    else if(m==2){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) ma=max(ma,and1(s[i],s[j]));
            }
        }
        cout<<ma;
        return 0;
    }
    else if(m==n){
        for(int i=2;i<=n;i++){
        s[1]=aaa(and1(s[1],s[i]));
        }
        for(int i=0;i<s[1].size();i++){
        if(s[1][i]=='1'){
            sum1+=z1;
        }
        z1=z1*2;
    }
        cout<<sum1;
        return 0;
    }
    else if(m==n-1){
    }
    return 0;
}
