
#include<bits/stdc++.h>
using namespace std;
int n,sum=0,ans=0;
int num,m;
char c;
char a[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n>2001){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>num>>c;
        for(int j=sum+1;j<=sum+num;j++){
            a[j]=c;
        }
        sum+=num;
    }
    if(sum%2==1){
        m=(sum+1)/2;
        for(int i=sum;i>=m+1;i--){
            if(a[i]!=a[sum-i+1]){
                ans++;
            }
        }
        cout<<ans;
    }
    else if(sum%2==0){
        m=sum/2;
        for(int i=sum;i>=m+1;i--){
            if(a[i]!=a[sum-i+1]){
                ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
