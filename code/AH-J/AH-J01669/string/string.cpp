#include<bits/stdc++.h>
using namespace std;
char a[200000001],b[200000001];
int main(){
long long n,c[200001],sum=0,f;
ifstream fin("string.in");
ofstream fout("string.out");
fin>>n;
for(int i=1;i<=n;i++){
fin>>c[i]>>b[i];
sum+=c[i];
}
int j=0;
for(int i=1;i<=sum;i++){
a[i]=b[j];
c[j]--;
if(c[j]==0)
j++;
}
for(int i=1;i<=sum;i++){
if(a[i]!=a[sum-i+1]){
f++;
}
}
fout<<f;
return 0;
}
