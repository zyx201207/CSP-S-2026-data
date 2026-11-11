#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    long long a[200005][2]={0};
    int n;
    cin>>n;
    int l=1,r=n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    int ans=0;
    while(l<r){
        if(a[l][1]==a[r][1]){
            if(a[l][0]==a[r][0]){
                l++;
                r--;
            }else if(a[l][0]>a[r][0]){
                a[l][0]-=a[r][0];
                r--;
            }else{
                a[r][0]-=a[l][0];
                l++;
            }
        }else{
            if(a[l][0]==a[r][0]){
                ans+=a[l][0];
                l++;
                r--;
            }else if(a[l][0]>a[r][0]){
                ans+=a[r][0];
                a[l][0]-=a[r][0];
                r--;
            }else{
                ans+=a[l][0];
                a[r][0]-=a[l][0];
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
