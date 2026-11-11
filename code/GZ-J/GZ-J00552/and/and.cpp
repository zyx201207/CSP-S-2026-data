//GZ-J0052 蒋承印 贵阳中天中学
#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n=0;
int m=0;
cin>>n>>m;
int a[100001]={};
for(int i=0;i<n;i++){
    cin>>a[i];
}
int ma=0;
if(m==1){
    for(int i=0;i<n;i++){
       if(ma<a[i]){
        ma=a[i];
       }
    }
}
if(m==2){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ma<(a[i]&a[j])){
                ma=a[i]&a[j];
            }
        }

    }

}
if(m==3){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int z=j+1;z<n;z++){if(ma<(a[i]&a[j]&a[z])){
                ma=a[i]&a[j]&a[z];
            }}


        }

    }

}
cout<<ma;
return 0;
}
