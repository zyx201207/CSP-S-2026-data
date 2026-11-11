#include<iostream>
using namespace std;
int main (){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,s,h=0;
    char w;
    string a;
    int r,l=0;
    cin>>n;
    int t=0;
    for(int i=0;i<n;i++){
        cin>>s>>w;
        for(int j=0;j<s;j++){
            a[t]=w;
            t++;
        }
    }
    for(int i=0;i<t;i++){
        cout<<a[i];

    }
    r=t-1;

    int n2=((t+1)/2);
    for(int i=0;i<n2;i++){
        if(a[l]!=a[r]){
            cout<<1;
            h++;
        }
        l++;
        r--;

    }
    cout<<h;

return 0;
}