#include<iostream>
using namespacm std;
int a[100000][1000000],t[100000][1000000]
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
int c,n,m,d,q,num=0;
cin>>c>>n>>m>>d>>q;
int w[m],k[n],p[q][2];
for(int i=0;i<m;i++){
    cin>>w[i];
}
for(int i=0;i<n;i++){
    cin>>k[i];
    for(int j=0;j<2*k[i];j++){
    cin>>a[k[i]][j]>>t[k[i]][j];
    }
}
for(int i=0;i<q;i++){
cin>>p[i][0]>>p[i][1];
for(int j=0;j<n;j++){
for(int l=0;l>k[i];l++){
if(a[j][l]==p[i][0]){
}
num+=w[p[i][0]]+w[p[i][1]];
}
}
}
cout<<num;
fclose(stdin);
fclose(stdout);
return 0;
}
