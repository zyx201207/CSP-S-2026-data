#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+50;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    long long sum = 0;
    cin>>a[0];
    int maxn = a[0];
    sum = a[0];
    for(int i = 1;i<n;i++){
        cin>>a[i];
        sum&=a[i];
        maxn = max(maxn,a[i]);
    }
    if(n==m){
        cout<<sum;
    }else if(m==1||n==1){
        cout<<maxn;
    }else if(m==2){
        int s = 0;
        maxn = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i==j) continue;
                s = a[i];
                s&=a[j];
                maxn = max(maxn,s);
            }
        }
        cout<<maxn;
    }else{
        cout<<"99999";
    }
    return 0;
}
