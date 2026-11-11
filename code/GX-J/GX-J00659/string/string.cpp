#include <bits/stdc++.h>
using namespace std;
int n,cishu,a[200005];
string str,str_swap,c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++){
            str+=c[i];
        }
        for(int j=a[i];j>0;j--){
            str_swap+=c[i];
        }
    }
    int k=0;
    while(str==str_swap){
        if(str[k]==str_swap[k])
            continue;
        else{
            str_swap[k]=str[k];
            cishu++;
        }
    }
    cout<<cishu;
}