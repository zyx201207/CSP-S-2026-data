#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,a[1000005];
char c[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    int i=1,j=n;
    while(i<j){
        if(c[i]!=c[j]){
            if(a[i]<a[j]){
                ans+=a[i];
                a[j]-=a[i];
                a[i]=0;
                i++;

            }else if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                a[j]=0;
                j--;
            }else{
                ans+=a[i];
                a[j]=0;
                a[i]=0;
                i++;
                j--;
            }
        }else if(a[i]!=a[j]){
            if(a[i]>a[j]){
                a[i]-=a[j];
                a[j]=0;
                j--;
            }else{
                a[j]-=a[i];
                a[i]=0;
                i++;
            }
        }else{
            a[i]=0;
            a[j]=0;
            i++;
            j--;
        }
    }
    cout<<ans;
    return 0;
}
