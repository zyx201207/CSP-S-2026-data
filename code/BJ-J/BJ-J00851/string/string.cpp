#include<bits/stdc++.h>
using namespace std;
    char cc[10000000000005];
    char c2[50000005];
int main(){
    freopen("string.in","t",stdin);
    freopen("string out","w",stdout);
    int n;
    cin>>n;
    int a1=0,a2;
    for(int i=1;i<=n;i++){
    int a;
        cin>>a;
        a1+=a;
        a2=a1-a+1;
        char c;
        cin>>c;
        for(int i=a2;i<=a1;i++){
            cc[i]==c;
        }
    }for(int i=1;i<=a1/2;i++){
    c2[i]=cc[i];
    }int num=0;
    for(int i=1;i<=a1/2;i++){
        if(cc[i+(al+1)/2]==c2[al/2+1-i]){
            num++;
        }
    }cout<<num;
return 0;
}
