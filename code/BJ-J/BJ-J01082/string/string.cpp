#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans,tot;
long long a[200001],w[200001];
char c[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long i=1,j=n;
    while(i+1<=j){
        if (c[i]==c[j]){
            if (a[i]>a[j]){
                a[i]-=a[j];
                j--;
            }else if (a[i]==a[j]){
                i++,j--;
            }else{
                a[j]-=a[i];
                i++;
            }
        }else{
            //改动较小那一方
            if (a[i]<a[j]){
                sum+=a[i];a[j]-=a[i];
                i++;
            }else if (a[i]>a[j]){
                sum+=a[j];
                a[i]-=a[j];j--;
            }else{
                sum+=a[i];
                i++,j--;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
