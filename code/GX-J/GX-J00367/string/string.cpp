#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int k=0;
    int n;
    cin>>n;
    char c;
    string x;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        cin>>c;
        for(int j=0;j<a;j++){
                int num=i*a;
            x[i*j+num]=c;
        }
    }
    for(int y=0;y<x.size();y++){
        int h=x.size();
        if(x[h]==x[y]){
            k==1;
        }
        else{
            k==0;
        }
        h--;
    }
    if(k==1){
        cout<<0;
    }
    else{
        cout<<3;
    }
    return 0;
}
