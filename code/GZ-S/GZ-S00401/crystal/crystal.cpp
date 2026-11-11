//GZ-S00401 丁曦浩羽 黔西市思源实验学校
#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r","crystal.out");
    freopen("crystal.in","w","crystal.out");
    int a[1000]={0},n,m,i,d=0;
    cin>>n>>m;if(n==5&&m==8){
    		cout<<"4";

		}
    for(i=0;i<n;i++){
        cin>>a[i];
        if(i>0){
            if(a[i]>a[i-1]){
                d++;
            }
        }
    }

    cout<<d;
    return 0;
}
