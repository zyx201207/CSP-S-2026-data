#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
long long a[n],b=1,maxn=0,many=0;
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a,a+n);
for(int i=0;i<n;i++){
    if(a[i]==a[i+1]){
        if(many<b){
            many=b;
            maxn=a[i];
        }
        b++;
    }
    else{
        b=1;
        continue;
    }
}
if(many!=0){
    for(int i=n-1;i>=0;i--){
        if(a[i]==maxn&&a[i-1]!=maxn){
            if(m>=a[i]-a[i-1]){
                a[i-1]=maxn;
                m-=a[i]-a[i-1];
                many++;
            }
            else break;
        }
    }
}
else{
    for(int i=n-1;i>=0;i--){
        if(a[i]==a[n/2]&&a[i-1]!=a[n/2]){
            if(m>=a[i]-a[i-1]){
                a[i-1]=a[n/2];
                m-=a[i]-a[i-1];
                many++;
            }
            else break;
        }
    }
}
cout<<many;
return 0;
}
