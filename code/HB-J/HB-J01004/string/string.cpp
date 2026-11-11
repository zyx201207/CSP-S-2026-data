#include <bits/stdc++.h>
using namespace std;
struct node{
    int t;
    char c;
    long long num;
};
node a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].t;
        cin>>a[i].c;
        a[i].num=a[i-1].num+a[i].t;
    }
    long long sum=0,m=0;
    int l=1,r=n;
    while(l<r){
        if(a[l].t==0){
            l++;
        }
        if(a[r].t==0){
            r--;
        }
        m=min(a[l].t,a[r].t);
        if(a[l].c==a[r].c){
            a[l].t-=m;
            a[r].t-=m;
        }
        else{
            a[l].t-=m;
            a[r].t-=m;
            sum+=m;
        }
    }
    cout<<sum;
    return 0;
}
