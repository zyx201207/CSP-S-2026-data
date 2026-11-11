#include<bits/stdc++.h>
using namespace std;

struct NUM{
    int num;
    int yi;
}a[2000005]={};

int f(int n){
    int all=0;
    while(n){
        all+=(n-((n>>1)<<1));
        n=n>>1;
    }
    return all;
}

bool cmp(NUM x,NUM y){
    if(x.yi==y.yi) return x.num>y.num;
    else return x.yi>y.yi;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,sum=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i].num;
        a[i].yi=f(a[i].num);
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n-m+1;i++){
        int s=a[i].num;
        for(int j=i+1;j<i+m;j++){
            s=s&a[j].num;
        }
        if(s>=sum) sum=s;
    }
    cout<<sum;
    return 0;
}
