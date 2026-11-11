#include<bits/stdc++.h>
using namespace std;
//freopen("crystal.in","r",stdin);
//freopen("crystal.out","w",stdout);
int main(){
int c,n,m,d,q,w;
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
    cin>>w[i];

    if(a[n/2]-a[n/2-1]>=a[n/2]-a[n/2-2]&&a[n/2]-a[n/2-1]>=a[n/2+1]-a[n/2]&&a[n/2]-a[n/2-1]>=a[n/2+2]-a[n/2]){
       ans=a[n/2]-a[n/2-1];
       if(m-ans>=0);
       m=m-ans;
       sum++;
       ans=0;
       ans=min(a[n/2]-a[n/2-2],a[n/2+1]-a[n/2],a[n/2+2]-a[n/2]);
       if(m-ans>=0);
       m=m-ans;
       sum++;
       }

       ans=min(a[n/2]-a[n/2-1],a[n/2+1]-a[n/2],a[n/2+2]-a[n/2]);
       if(m-ans>=0);
       m=m-ans;
       sum++;
       }

       ans=0;
       ans=min(a[n/2]-a[n/2-2],a[n/2]-a[n/2-1],a[n/2+2]-a[n/2]);
       if(m-ans>=0);
       m=m-ans;
       sum++;
       }
       if(a[n/2+2]-a[n/2]>=a[n/2]-a[n/2-2]&&a[n/2+2]-a[n/2]>=a[n/2+1]-a[n/2]&&a[n/2+2]-a[n/2]>=a[n/2]-a[n/2-1]){
       ans=a[n/2+2]-a[n/2];
       if(m-ans>=0);
       m=m-ans;
       sum++;
       ans=0;
       ans=min(a[n/2]-a[n/2-2],a[n/2+1]-a[n/2],a[n/2]-a[n/2-1]);
       if(m-ans>=0);
       m=m-ans;
       sum++;
       }
       if(m-ans>=0);
       m=m-ans;
       sum++;
       if(ans==a[n/2]-a[n/2-1]){
       ans=0;
       ans=min(a[n/2]-a[n/2-2],a[n/2+1]-a[n/2],a[n/2+2]-a[n/2]);
       if(m-ans>=0);
       m=m-ans;
       sum++;
       }
}
}
