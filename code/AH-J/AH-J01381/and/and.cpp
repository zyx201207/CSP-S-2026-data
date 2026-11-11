#include<bits/stdc++.h>
using namespace std;
int s[200005],c[200005];
int n,m,maxs;
string zh(int a){
    string s;
    while(a){
        if(a%2==1){
            s='1'+s;
        }else{
            s='0'+s;
        }
        a/=2;
    }
    return s;
}
int js(string a,string b){
    int la=a.size();
    int lb=b.size();
    int maxs=max(la,lb),sum=0;
    if(la<lb){
        for(int i=1;i<=lb-la;i++){
            a='0'+a;
        }
    }else{
        for(int i=1;i<=la-lb;i++){
            b='0'+b;
        }
    }
    int ans=1;
    for(int i=maxs-1;i>=0;i--){
        if(a[i]=='1'&&b[i]=='1'){
            sum+=ans;
        }
        ans*=2;
    }
    return sum;
}
int ts(int d,int t,int pos){
    c[pos]=-1;
    int ss=0;
    if(t==m+1){
        return d;
    }
    for(int i=1;i<=n;i++){
        if(c[i]==-1){
            continue;
        }
        ss=js(zh(d),zh(c[i]));
        d=max(ss,ts(ss,t+1,i));
    }
    return d;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        maxs=max(maxs,s[i]);
        c[i]=s[i];
    }
    if(m==1){
        cout<<maxs;
        return 0;
    }
    if(m==n){
        int sum;
        for(int i=2;i<=n;i++){
            if(i==2){
                sum=js(zh(s[1]),zh(s[2]));
            }else{
                sum=js(zh(sum),zh(s[i]));
            }
        }
        cout<<sum;
        return 0;
    }
    int sum=0,t=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[j]=s[j];
        }
        int d=s[i];
        sum=max(sum,ts(d,t+1,i));
    }
    cout<<sum;
    return 0;
}
