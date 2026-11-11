#include<bits/stdc++.h>
using namespace std;
struct node{
long long b,l,r;
char c;
}a[200050];
long long n;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
a[1].l=1;
cin>>a[1].b>>a[1].c;
a[1].r=a[1].b;
for(int i=2;i<=n;i++){
cin>>a[i].b>>a[i].c;
a[i].l=a[i-1].r+1;
a[i].r=a[i].l+a[i].b-1;
}
long long ans=0,na=a[n].r,ls=1,rs=a[n].r+1,cntl=1,cntr=n;
while(ls<rs&&cntl<cntr){
ls=a[cntl].r;
if(ls>(na+1)/2||rs<(na+1)/2)ls=(na+1)/2;
while(1){
if(a[cntr].l+ls-1>=na){
if(a[cntl].c!=a[cntr].c)ans+=rs-a[cntr].l;
cntr--;
rs=a[cntr].r;
}
else{
rs=na-ls+1;
if(a[cntl].c!=a[cntr].c)ans+=a[cntr].r-rs+1;
break;
}
//cout<<ans<<' '<<ls<<' '<<rs<<' '<<cntl<<' '<<cntr<<"\n";
}
cntl++;
//cout<<ans<<' '<<ls<<' '<<rs<<' '<<cntl<<' '<<cntr<<"\n";
}
cout<<ans;
return 0;
}
