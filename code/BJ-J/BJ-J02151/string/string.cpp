#include<bits/stdc++.h>
using namespace std;
long long l[1000000],r[1000000],a[1000000];
char c[1000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,l1=1,r1=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        r1+=a[i];
        l[i]=l1;
        r[i]=r1;
        l1=r1+1;
    }
    long long mid=(r1+1)/2,an=0;
    l1=1;
    long long li=1,ri=n;
    while(l1<r1){
        if(l1>r[li])li++;
        if(r1<l[ri])ri--;
        if(li==ri){
            break;
        }
        if(c[li]==c[ri]){
            r1=r1-min(a[ri],a[li]);
            l1=l1+min(a[ri],a[li]);
            //cout<<li<<" "<<ri;
        }else{
            an+=min(r[li]-l1+1,r1-l[ri]+1);
            l1=l1+min(r[li]-l1+1,r1-l[ri]+1);
            r1=r1-min(r[li]-l1+1,r1-l[ri]+1);
        }
        //cout<<l1<<" "<<r1<<"\n";
        //l1=10;
        //r1=1;

    }
    cout<<an;
}
