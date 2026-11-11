#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,cnt=0;
struct node{
    long long a;
    char c;
}arr[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].a>>arr[i].c;
        cnt+=arr[i].a;
    }
    long long l=1,r=n;
    while(l<r){
        if(arr[l].a>arr[r].a){
            if(arr[l].c!=arr[r].c)ans+=arr[r].a;
            arr[l].a-=arr[r].a;
            r--;
        }else if(arr[l].a==arr[r].a){
            if(arr[l].c!=arr[r].c)ans+=arr[r].a;
            l++,r--;
        }else{
            if(arr[l].c!=arr[r].c)ans+=arr[l].a;
            arr[r].a-=arr[l].a;
            l++;
        }
    }
    cout<<ans;
    return 0;
}