#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,ans;
    string s,a,b;
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){cout<<0;return 0;}
    for(int i=1;i<=n;i++){
        cin>>ans>>s;
        for(int i=1;i<=ans;i++) a+=s;
    }
    long long sum=a.size();
    for(int i=sum-1;i>=0;i--){
        b[i]=a[sum-i-1];
   }
   long long aans=0;
    if(sum/2==1){
        for(int i=sum/2+1;i<=sum-1;i++){
            if(a[i]!=b[i]) aans++;
        }
    }
    else{
        for(int i=sum/2;i<=sum-1;i++){
            if(a[i]!=b[i]) aans++;
        }
    }
    cout<<aans;
}
