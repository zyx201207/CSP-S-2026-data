#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[500000];
bool May(int a[],int s,int f,int t){
    int min_a=0;
    for(int i=s;i<f;i++){
        min_a+=a[i+1]-a[i];
    }
    if(min_a>t)return 0;
    return 1;
}
bool help(int a[],int n){
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]!=1)return 0;
    }
    return 1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,max_sum=-1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(help(a,n)==1){
        int sum=0;
        for(int i=1;i<=n;i++){
            if(m-i>=0){
                m-=i;
                sum++;
            }
        }
        if(sum==n-1)sum++;
        if(sum>n)sum--;
        cout<<sum;
        return 0;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i;j<n;j++){
             if(May(a,i,j,m)==1)cnt++;
             else break;
        }
        if(cnt>max_sum)max_sum=cnt;
    }
    cout<<max_sum;
    return 0;
}
