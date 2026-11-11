#include <bits/stdc++.h>

using namespace std;
int n,m,num=0,sum=0;
int a[100005];
int b[100005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin >>n>>m;
for(int i=0;i<n;i++){
    cin >>a[i];
}
for(int i=1;i<=n;i++){
        sum=i;
    while(b[i]<a[i+1]){
        b[i]=a[i]+1;
        if(b[i-1]<a[i+1]){
        b[i-1]+1;
        num++;
    }
    num++;
    }
    if(num=m){
        cout <<i;
        break;
    }

}


fclose(stdin);
fclose(stdout);
return 0;
}
