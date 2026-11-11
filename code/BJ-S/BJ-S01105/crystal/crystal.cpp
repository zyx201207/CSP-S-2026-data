#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[500010];
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int mid=a[n/2+1],num=n/2;
    while(m>0&&num>0){
        if(a[num]<mid){
            a[num]++;
            m--;
        }
        else{
            num--;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]==mid){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
