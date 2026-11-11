#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
struct s{
    long long id,s1;
};
s a[200005];
long long count1(long long x){
    long long sum=0;
    while(x!=0){
        sum+=x%2;
        x/=2;

    }
    return sum;
}
bool cmp(s x,s y){
    if(x.s1!=y.s1){
        return x.s1>y.s1;
    }
    return x.id>y.id;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i].id;
        a[i].s1=count1(a[i].id);

    }
    sort(a,a+n,cmp);
    sum=a[0].id;
    for(long long i=1;i<m;i+=1){
        sum=(sum & a[i].id);
    }
    cout<<sum;
    return 0;
}
