//GZ-J00196 黄钰涵 贵阳市观山湖外国语实验中学
#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;
cin>>n;
int a[n+1];
for(int i=0;i<=n;i++){
    cin>>a[i];
}
int d=0;
for(int i=0;i<=n;i++){
            int b=a[i] and a[i+1];


    if(b>d){
        d=b;
    }
}
cout<<d;
fclose(stdin);
fclose(stdout);
return 0;
}
