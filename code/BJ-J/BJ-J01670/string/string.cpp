#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],a2[N];
char c[N];
int n;
long long sum=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a2[i]=a[i];
        cin>>c[i];

    }
    int l=1,r=n;
    while(l<=n+1){
        if(c[l]==c[r]){
            if(a[l]>a2[r]){
                a[l]-=a2[r];
                r--;
            }else if(a[l]==a2[r]){
                l++,r--;
            }
            else{
                a2[r]-=a[l];
                l++;
            }
        }
        else{
            if(a[l]>a2[r]){
                sum+=a2[r];
                a[l]-=a2[r];
                r--;
            }else if(a[l]==a2[r]){
                sum+=a[l];
                l++,r--;
            }
            else{
                sum+=a[l];
                a2[r]-=a[l];
                l++;
            }
        }
    }
    cout<<sum/2<<endl;
    return 0;
}
