#include<bits/stdc++.h>
using namespace std;
int n,temp_n;
int temp_i=1;
unsigned long long ans;
long long a[200050];
char s[200050];
void dfs(int temp_n,int temp_i){
    for(int i=temp_i;i<=n/2;i++){
    if(s[i]!=s[temp_n]){
        if(a[i]>=a[temp_n]){
            ans+=a[i]-a[temp_n];
            a[i]=a[i]-a[temp_n];
            temp_n--;
            dfs(temp_n,temp_i);
            break;
        }
        else {
            ans+=a[temp_n]-a[i];
            a[temp_n]=a[temp_n]-a[i];
        }
    }
    else{if(a[i]>=a[temp_n]){
            a[i]=a[i]-a[temp_n];
            temp_n--;
    }
        else if(a[temp_n]>a[i]){
            a[temp_n]=a[temp_n]-a[i];
        }
    }
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    temp_n=n;
    for(int i=i;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    dfs(temp_n,temp_i);
    cout<<ans;
    return 0;
}
