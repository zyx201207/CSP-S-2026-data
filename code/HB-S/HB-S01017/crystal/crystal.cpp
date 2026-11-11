#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
long long m;
cin>>n>>m;
long long a[n];
int cha;
for(long long i=0;i<n;i++){
    cin>>a[i];
    if(a[i]>0){
        cha=a[i]-a[i-1];
    }
}
cout<<cha;
sort(a,a+n);
int z=m/cha;
cout<<z;
int k=0;
int jianshu=1;
while(z-jianshu>0){

   z=z-jianshu;
   jianshu++;
   k++;
}
cout<<k+1;
return 0;
}
