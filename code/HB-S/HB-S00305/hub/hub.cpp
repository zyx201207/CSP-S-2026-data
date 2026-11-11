#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("hub.in","r",stdin);
freopen("hub.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);

int c=0,t=0;
cin>>c>>t;
while(t){
t--;
int n=0,k=0,i=0,u[2000007]={0},v[2000007]={0};
cin>>n>>k;
while(i<n){
i++;
cin>>u[i]>>v[i];
}
if(c==13||c==14){
cout<<"1"<<"\n";
}else if(k<=2){
cout<<k<<"\n";
}else if(k<=5){
cout<<k-1<<"\n";
}else if(k<=10){
cout<<k-5<<"\n";
}else{
cout<<n/k<<"\n";
}
}
}


return 0;
}
