#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum,ans;
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    ans=n;
    for(int i=1;i<=ans;i++){
        if(a[i]<a[ans]){
            if(c[i]!=c[ans]){
                sum+=a[i];
                a[ans]-=a[i];
            }else{
                a[ans]-=a[i];
            }
        }else if(a[i]>a[ans]){
            if(c[i]!=c[ans]){
                sum+=a[ans];
                a[i]-=a[ans];
                ans--;
                i--;
            }else{
                a[i]-=a[ans];
                ans--;
                i--;
            }
        }else{
            if(c[i]!=c[ans]){
                sum+=a[i];
                ans--;
            }else{
                ans--;
            }
        }
    }
    cout<<sum;
    return 0;
}
