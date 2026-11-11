#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
struct num{
    int id,amount;
}b[500010];
int main(){
    freopen("crystal.out","w",stdout);
    freopen("crystal.in","r",stdin);    
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    int t=m;
    sort(a,a+n);
    int bi=0;
    for(int i=0;i<n;i++){
        int amountofnum=0;
        b[bi].id=a[i];
        b[bi].amount++;
        while(a[i+1]==a[i]){
            b[bi].amount++;
            i++;
        }
        cout<<b[bi].id<<' '<<b[bi].amount<<'\n';
        bi++;
    }
    int bn=bi,total=0;
    bi=0;
    while(t>0 && bi+1<bn){
        long long amount=b[bi].amount,id=b[bi].id,nextid=b[bi+1].id;
        long long diff=nextid-id,needt;
        total+=amount;
        needt=total*diff;
        if(t>=needt)t-=needt;
        else {
            cout<<bn<<' '<<bi<<' '<<amount<<' '<<total<<' '<<diff<<' '<<needt<<' '<<t<<'\n';
            break;
        }
        cout<<bi<<' '<<amount<<' '<<total<<' '<<diff<<' '<<needt<<' '<<t<<'\n';
        bi++;
    }
    if(t==0 or bi+1>=bn)total+=b[bi].amount;
    cout<<total;
    return 0;   
}