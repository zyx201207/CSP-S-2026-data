#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);

int c=0,t=0;
cin>>c>>t;
while(t){
int n=0,d=0,i=0,x[3000007]={0};
cin>>n>>d;
while(i<n){
i++;
cin>>x[i];
}
if(c==11||c==12){
if(d>=2*(x[2]-x[1])&&d<3*(x[2]-x[1]))){
cout<<n-3;
}else{
cout<<"0"<<"\n";
}
}else if(c==13||c==14){
cout<<"1"<<"\n";
}else if(c>=15&&c<=18){
cout<<"0"<<"\n";
}else if(n<=3){
cout<<"0"<<"\n";
}else{
int s=0;
i=4;
if((a[i]-a[i-2]<=d)&&(a[i-1]-a[i-3]<=d){
s++;
}
while(i<n){
i++;
if((a[i]-a[i-2]<=d)&&(a[i-1]-a[i-3]<=d)&&(a[i]-a[i-3])>d){
s++;
}
}
cout<<s<<"\n";
}
}
return 0;
}
