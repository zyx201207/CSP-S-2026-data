#include <bits/stdc++.h>

using namespace std;
int c,t,n,d;
int a[100005];
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
           cin >>c>>t>>n>>d;
while(d--){
        for(int i=1;i<=n;i++){
            cin >>a[i];

        }

if(a[n]%n==0){
    cout <<1<<endl;
}else if(a[n]%d==1 && a[n-1]%d==0){
    cout <<2<<endl;
}
}

fclose(stdin);
fclose(stdout);
return 0;
}
