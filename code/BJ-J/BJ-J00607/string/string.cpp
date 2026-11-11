#include <iostream>
using namespace std;
int a[100000];
char b[100000];

int main (){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
int n,m=0;
cin>>n;
for(int i=1;i<=n;i++){
cin >>a[i]>>b[i];
}
for(int i=1;i<=n/2;i++){
    for(int j=n;j>=n/2;j--){
        if (b[i]==b[j]!&&b[i+1]==b[j-1]!){
            m=m+min(a[i],a[j]);
            
        }



    }

}
cout <<m;
return 0;
}
