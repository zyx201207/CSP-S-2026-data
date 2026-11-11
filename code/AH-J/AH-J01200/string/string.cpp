#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    long long ans=0;
    int i=1,j=n;
    while(i<j){
        if(a[i]>a[j]){
            if(c[i]!=c[j]){
                ans+=a[j];
            }
            a[i]-=a[j];
            j--;
        }else if(a[i]<a[j]){
            if(c[i]!=c[j]){
                ans+=a[i];
            }
            a[j]-=a[i];
            i++;
        }else{
            if(c[i]!=c[j]){
                ans+=a[i];
            }
            i++,j--;
        }
    }
    cout<<ans;
    return 0;
}
