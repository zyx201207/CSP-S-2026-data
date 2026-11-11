#include<bits/stdc++.h>
using namespace std;
bool tong[300005];

stack <long long> a;
long long n,m,sss[500099],cnt[300001];
void csp(long long z){
    if(z==0){
        return ;
    }
    for(int i=1-z+n;i<=n;i++){
        long long ccf=sss[i];
        if(!tong[ccf]){
            tong[ccf]=true;
        a.push(ccf);
        }
        else{
            while(a.top()!=ccf){
                tong[a.top()]=false;
                a.pop();
            }
        }
    }
     while(!a.empty()){
        cnt[a.top()]++;
        tong[a.top()]=false;
        a.pop();
    }
    csp(z-1);
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    if(n>31622){
            long long max_=-10086;
        for(int i=1;i<=n;i++){
                cin>>sss[i];
            if(sss[i]<max_){
                break;
            }
        max_=sss[i];
        }
        if(max_!=-10086){
            for(int i=1;i<=m;i++){
                cout<<i<<" ";
                return 0;
            }
        }
    }else if(m==1){
        for(int i=1;i<=n;i++){
            int xsq;
            cin>>xsq;
        }
        cout<<n;
        return 0;
    }else if(m==2){
        long long chinese_can_fly=0,chinese_need_t=0;
        for(int i=1;i<=n;i++){
            int zzzzz;
            cin>>zzzzz;
            if(zzzzz==1){
                chinese_can_fly++;
            }else{
                chinese_need_t++;
            }
        }
        cout<<chinese_can_fly<<" "<<chinese_need_t;
    }
    for(int i=1;i<=n;i++){
        long long ccf;
        cin>>ccf;
        sss[i]=ccf;
        if(!tong[ccf]){
            tong[ccf]=true;
        a.push(ccf);
        }
        else{
            while(a.top()!=ccf){
                tong[a.top()]=false;
                a.pop();
            }
        }
    }
    while(!a.empty()){
        cnt[a.top()]++;
        tong[a.top()]=false;
        a.pop();
    }
    csp(n-1);
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
//CCRHFBEHHDFHUWEHBUSHUUFVEDAHOEGYASOIXIEDHrn8EVrccAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHZJCCFCFCFCFCFCFCC CCFFCFFCFCFCFCCFCFUHOSAFFVBAUIR




