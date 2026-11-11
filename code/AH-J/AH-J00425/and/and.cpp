#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int n;
    int a;
};

int solve(int a){
    int ans=0;
    while(a!=0){
        char c;
        if(a%2==1)ans++;
        a/=2;
    }
    return ans;
}
bool cmp(node a,node b){
    //if(a.n!=b.n)return a.n>b.n;
    //return a.a>b.a;
    if(a.a!=b.a)return a.a>b.a;
    return a.n>b.n;
}
bool cmp1(node a,node b){
    if(a.n!=b.n)return a.n>b.n;
    return a.a>b.a;
    //if(a.a!=b.a)return a.a>b.a;
    //return a.n>b.n;
}
bool cmp2(node a,node b){
    return a.n>b.n;
    //if(a.a!=b.a)return a.a>b.a;
    //return a.n>b.n;
}
bool cmp3(node a,node b){
    return a.a>b.a;
    //if(a.a!=b.a)return a.a>b.a;
    //return a.n>b.n;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<node>b(n);
    for(int i=0;i<n;i++){
        cin>>b[i].a;
        //b[i].s=solve(b[i].a);
        b[i].n=solve(b[i].a);
    }
    sort(b.begin(),b.end(),cmp);
    int sum=b[0].a;
    for(int i=0;i<m;i++){
        sum=sum&b[i].a;
    }
    sort(b.begin(),b.end(),cmp1);
    int summ=b[0].a;
    for(int i=0;i<m;i++){
        summ=summ&b[i].a;
    }
    sum=max(sum,summ);
    sort(b.begin(),b.end(),cmp2);
    summ=b[0].a;
    for(int i=0;i<m;i++){
        summ=summ&b[i].a;
    }
    sum=max(sum,summ);
    sort(b.begin(),b.end(),cmp3);
    summ=b[0].a;
    for(int i=0;i<m;i++){
        summ=summ&b[i].a;
    }
    sum=max(sum,summ);
    cout<<sum;
    return 0;
}
