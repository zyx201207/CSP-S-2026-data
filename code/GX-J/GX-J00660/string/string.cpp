#include <bits/stdc++.h>
using namespace std;
long long  m[200005];
char b[200005];
int main(){

freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n;
cin>>n;
string a;
for(long long i=1;i<=n;i++){
        cin>>m[i]>>b[i];
}

long long ans=0;
long long l=1,r=n;

while(l<r){
    if(b[l]==b[r]){
        if(m[l]<m[r]){
            m[r]-=m[l];
            m[l]=0;
            l++;
        }
        else if(m[l]>m[r]){
            m[l]-=m[r];
            m[r]=0;
            r--;
        }
        else{
            m[r]=0;m[l]=0;
            l++;r--;
        }
    }
    else{
        if(m[l]<m[r]){
            ans+=m[l];
            m[r]-=m[l];
            m[l]=0;
            l++;
        }
        else if(m[l]>m[r]){
            ans+=m[r];
            m[l]-=m[r];
            m[r]=0;
            r--;
        }
        else{
            ans+=m[r];
            m[r]=0;m[l]=0;
            l++;r--;
        }
    }
}
cout<<ans;
return 0;
}
