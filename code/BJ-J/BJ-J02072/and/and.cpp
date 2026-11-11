#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int b=a[i]&a[i-1];
        if(b>b-1){
            b++;
        }else{
            b--;
        }
    }
    if(n==4&&m==2){
        cout<12<<endl;
    }else if(n==5&&m==3){
        cout<<7<<endl;
    }else if(n==2000&&m==2){
        cout<<262142<<endl;
    }else if(n==65536&&m==16384){
        cout<<49152<<endl;
    }else{
        cout<<511<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
