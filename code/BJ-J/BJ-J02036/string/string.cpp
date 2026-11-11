#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);

char s[1000000];
long long n,a[10000],num=0,sum=0;
for(int i=1;i<=n;i++){
    cin>>a[i]>>s[i];
    num=a[i];
}
long long q=0,p=1,num1=0;
while(num1<num/2){
num1=a[q];
a2[p]=a[q];
s2[p]=s[q];
}

q++;
p--;
for(i=1;i<=q;i++){
    s1[i]=s[i];
    a1[i]=a[i];
}
s1[q]=s[q];
a1[q]=num1-num/2;



while(1){
    if(a1>a2){
        
    }
}

return 0;
}
