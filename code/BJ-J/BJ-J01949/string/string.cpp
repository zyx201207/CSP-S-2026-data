#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.ans","w",stdout);
    int n;
    cin>>n;
    long long int a[n],sum=0,ans=0;
    char b[n];
    string s;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];

    }
    int l=0,r=n-1;
    while(r>=l){
        if(a[l]>a[r]){
            if(b[l]!=b[r]){
                ans+=a[r];
            }
            a[l]-=a[r];
            r--;
        }else if(a[l]<a[r]){
            if(b[l]!=b[r]){
                ans+=a[l];
            }
            a[r]-=a[l];
            l++;
        }else{
            if(b[l]!=b[r]){
                ans+=a[r];
            }
            r--;
            l++;
        }
    }
    cout<<ans;
}