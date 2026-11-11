#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);

int n,m,s=1;
cin>>n>>m;
int a[1000000]={0};
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){
    if(m!=0){
        if(a[i]<a[i+1]){
            a[i]++;
            m--;
        }
        if(a[i]=a[i+1]){
            s++;
            break;
        }
    }
}

cout<<s;
fclose(stdin);
fclose(stdout);

return 0;
}
