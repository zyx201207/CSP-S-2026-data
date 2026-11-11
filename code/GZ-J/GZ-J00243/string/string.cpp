//GZ-J00243 安顺市实验学校 李浩淼
#include<bits/stdc++.h>
using namespace std;
char c,h[200000005];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,a,o=0,m=0;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a>>c;
    for(int i=m;i<m+a;i++){
    h[i]=c;
    }
    m+=a;
}
m-=1;
for(int i=0;m-i>=1&&m!=i;i++){
    if(h[i]!=h[m])
        o++;
    m-=1;
}
cout<<o;
return 0;
}
