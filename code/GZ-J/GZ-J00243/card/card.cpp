//GZ-J00243 安顺市实验学校 李浩淼
#include<bits/stdc++.h>
using namespace std;
int a[100005],d[100005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){
        int b[100005],c[100005];
for(int j=1+i-1;j<=n;j++)
{int k=1;
if(c[a[j]]==0){//他没有记录
    b[k]=a[j];
    c[b[k]]=k;
    k++;
}
else{
    for(int f=c[a[j]];f<=k;f++){
            c[b[f]]=0;
    b[f]=0;
    --k;
    }
    ++k;
    b[k]=a[j];
    c[b[k]]=k;
    cout<<k<<' ';
    k++;
}
}
for(int j=1;j<=m;j++){
    if(c[j]!=0){
        d[j]++;
        cout<<j<<' ';
    }
}
cout<<endl;
}
for(int i=1;i<=m;i++){
   cout<<d[i]<<' ';
}
return 0;
}
