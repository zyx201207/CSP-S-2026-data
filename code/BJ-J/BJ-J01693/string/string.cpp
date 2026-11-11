#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans=0;
char s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i]>>s[i];
    }
    for(int i = 1,j = n;i<=j;){
        if(s[i]!=s[j]){
            if(a[i]<a[j]){
                ans+=a[i];
                a[j]-=a[i];
                i++;
            }else if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                j--;
            }else if(a[i]==a[j]){
                ans+=a[j];
                j--;
                i++;
            }
        }else{
            if(a[i]<a[j]){
                a[j]-=a[i];
                i++;
            }else if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
            }else if(a[i]==a[j]){
                j--;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}

