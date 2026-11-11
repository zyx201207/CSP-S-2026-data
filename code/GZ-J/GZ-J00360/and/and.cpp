\\GZ-J00360贵阳市观山湖区第一高级中学祝廷嘉
#include<bits/stdc++.h>
using namespace std;
int a,b,c[1000];
main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
cin>>a>>b;

for(int i=1;i<=a;i++){
    cin>>c[i];
}
sort(c[1],c[a]);
for(int i=2;i<=b;i++){
    c[i]=a[i]&a[i-1];

}
cout<<c[b];




return 0;
}


