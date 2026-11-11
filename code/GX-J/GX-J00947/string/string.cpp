#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long a[20000000000];
long long a1[20000000000];
long long a2[20000000000];
long long a3[20000000000];
long long a4[20000000000];
int s,s1;
int n,h;
long long z=0;
cin>>n;
for(int i=0;i<=n;i++){
    cin>>s>>s1;
    for(int j=0;j<=s;j++){
        a[j]=s1;
        h=ads(s*n/2)
        for(int x=0;x<=h;x++){
            a1[x]=a[j];
        }
        for(int w=s*n;w>=h;w--){
            a2[w]=a[j];
        }
   }

}
for(int m=0;m<=s*n;m++){
    if(a1[m]=a2[m]){
    a3[m]=a1[m];
    a4[m]=a2[m];
}
    else{
    z++;
    a3[m]=a1[m];
    a4[m]=a1[m];
}

}
cout<<z;
return 0;
}
