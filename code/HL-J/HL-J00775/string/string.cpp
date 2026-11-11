#include <iostream>
using namespace std;
int main(){
    ios::sync_with_studio(false);
    cin.(nullptr);
    freopen("string.in","r");
    freopen("string.out","w");
    long long n,ai,i,j;
    bool flag;
    string ci,a;
    for(i=0;i<n;i++){
        cin>>ai>>ci;
        for(j=1;j<=ai;j++){
            a+=ci;
        }
    }
    long long le=getline(cin.a);
    for(i=0;i<le/2+1;i++){
        for(j=le;j>le/2+1;j--){
            if(a[i]==a[j])  flag=true;
            else{
                flag=false;
                break;
            }
        }
    }
    if(flag==true)  cout<<0;
}
