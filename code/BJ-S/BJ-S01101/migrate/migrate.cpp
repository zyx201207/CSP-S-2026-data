#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("migrate.in";"r";stdin);
    //freopen("migrate.out";"w";stdout);
    int c,t;
    cin>>c>>t;
    int n[t+1];
    int d[t+1];
    for(int i=1;i<=t;i++){
        cin>>n[i];
        cin>>d[i];
        int a[n[i]+1];
        for(int j=1;j<=n[i];j++){
            cin>>a[j];
        }
        for(int j=1;j<=n[i]-1;j++){
            if(a[j+1]-a[j]==d[i]){
                for(int k=j+1;k<=n[i]-1;k++){
                    int z=a[j+2]-d[i];
                    a[j+2]=a[j+1];
                    a[j+1]=z;
                }
            }
            n[i]-=1;
        }
        int sum=0;
        for(int j=1;j<=n[i]-3;j++){
            if((a[j+2]-a[j]<=d[i]) && (a[j+3]-a[j+1]<=d[i])){
                sum++
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}