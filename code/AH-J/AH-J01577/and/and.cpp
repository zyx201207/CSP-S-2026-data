#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int a[2005];
string sh[2005],ans[2005];
string to_2(int a){
    string s;
    int cnt=0;
    while(a){
        if(a%2==0)s+='0';
        else s+='1';
        a/=2;
        cnt++;
    }
    return s;
    /*int sum=0;
    for(int i=0;i<cnt;i++){
        sum+=(s[i]-'0')*pow(2,i);
    }
    return sum;*/
}
int do_and(string a,string b){
    int l=max(a.size(),b.size());
    int sum=0;
    for(int i=l;i>=0;i--){
        if(a[i]==1&&b[i]==1){
            sum+=pow(2,i);
        }
    }
    cout<<sum;
}
string do_any(int n){
    for(int i=1;i<=n;i++){
        sh[i]=to_2(a[i]);
    }
    for(int i=1;i<n;i++){
       ans[i+1]=to_2(do_and(sh[i],sh[i+1]));
    }
    return ans[n];
}
int for_2_to_10(string a){
    int cnt=0;
    int sum=0;
    while(cnt>a.size()){
        sum+=a[cnt]*pow(2,cnt);
        cnt++;
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    int maxa=0,maxb=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>maxa)maxa=a[i];
    }
    if(m==1)cout<<maxa;
    if(m==2){
    //cout<<to_2(a[1])<<' '<<to_2(a[2]);

        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(do_and(to_2(a[i]),to_2(a[j]))>maxb)maxb=do_and(to_2(a[i]),to_2(a[j]));
            }
        }
        cout<<maxb;
    }
    if(m==n)cout<<for_2_to_10(do_any(n));

    return 0;
}
