//GZ-S00250 ³ÂÖÂÐÇ 
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
long long n,m;
long long a[10005];
int main(){
//freopen("crystal.in","r",stdin);
//freopen("crystal.out","w",stdout);
cin>>n>>m;
int c=m,d=1,max=-1; 
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        int b=a[j+1]-a[j];
        if(b<=m){
            if(m-b<=0){
                m+=c;
                continue;
            }
            else{
                a[j]+=b;
                m-=b;
                d++;
			}
        }
        if(d>=max){
            max=d;
            d=0;
        }
    }
}
cout<<max+d;
return 0;
}
