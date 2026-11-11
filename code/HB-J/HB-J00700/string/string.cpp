#include<bits/stdc++.h>
using namespace std;
struct stu1{
    long long number;
    string zf;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n;
    cin>>n;
    long long min1=LLONG_MAX;
    long long m1=LLONG_MAX;
    for(int i=1;i<=n;i++){
        cin>>a[i].number>>a[i].zf;
        m1=min(m1,a[i].number);
    }
    int flag=1;
    if(n==1){
        cout<<0;
        return 0;
    }
    long long ans=0;
    for(int i=2;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i].zf!=a[j].zf){
                ans+=a[i].number;
                a[j].zf=a[i].zf;
                flag=0;
            }
        }
        min1=min(min1,ans);
    }
    if(flag==1){
        cout<<0;
        return 0;
    }

    if(n==2){
        cout<<m1;
        return 0;
    }
    cout<<min1;
    return 0;
}
