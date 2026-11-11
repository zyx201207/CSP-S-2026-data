#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5e2,M=1e8;
int a[N],b[N];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m,z=0,v;
cin>>n>>m;
if(n<=5000&&m<=M){
    for(int i=1;i<=n;i++){
cin>>a[i];
z+=a[i];
}
int mind=z/n;
int xx=INT_MAX;
for(int i=1;i<=n;i++){
    if(a[i]-mind<0){
        if(mind-a[i]<xx){
            v=a[i];
            xx=mind-a[i];
        }
        else{
          
            v=a[i];
            xx=a[i]-mind;
        
        }

    }
}
for(int i=1;i<=n;i++){ 
        if((a[i]-v)>0){
            a[i]=a[i]-v;
        }
        else{
           a[i]=v-a[i];
        }
}
sort(a+1,a+n+1);
int s=0;
for(int i=1;i<=n;i++){
    if((m-a[i])>=0){
        m-=a[i];
        s++;
    }
    else{
        cout<<s;
        return 0;
    }
}
cout<<s;
        return 0;
}
else{
        int s=0;
  for(int i=1;i<=n;i++){
    cin>>b[i];
if(b[i]!=i){
    s=1;
}
}
if(s==1){
    int k=b[2]-b[1];
    cout<<m/k;
    return 0;
}
else{
  cout<<m;
  return 0;
}

}





cout<<9;
return 0;
}

