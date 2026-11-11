#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char x[200005];
long long sum=0,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>x[i];
        sum+=a[i];
    }
    int i=1,j=n;
    while(i<j){
        if(a[i]==0)i++;
        if(a[j]==0)j--;
        if(x[i]!=x[j]){
            if(a[i]>a[j]){
                a[i]-=a[j];
                ans+=a[j];
                a[j]=0;
                x[j]=x[i];
            }else{
                a[j]-=a[i];
                ans+=a[i];
                a[i]=0;
                x[i]=x[j];
            }
        }else{
            if(a[i]>a[j]){
                a[i]-=a[j];
                a[j]=0;
            }else{
                a[j]-=a[i];
                a[i]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}
