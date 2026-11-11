#include<bits/stdc++.h>
using namespace std;
struct node{
    int t;
    char s;
}a[2000005];
int n;
long long ans=0;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i].t>>a[i].s;
}
int l=1,r=n;
while(l!=r){
    if(a[l].s!=a[r].s){
        if(a[l].t<=a[r].t){
            a[r].t-=a[l].t;
            ans+=a[l].t;
            l++;
        }else{
            a[l].t-=a[r].t;
            ans+=a[r].t;
            r--;
        }
    }else{
        if(a[l].t<=a[r].t){
            a[r].t-=a[l].t;
            l++;
        }else{
            a[l].t-=a[r].t;
            r--;
        }
    }
}
cout<<ans;
return 0;
}
