#include<iostream>
#include<string>
using namespace std;
int a[100000];
string c,s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            char x;
            cin>>x;
            for(int j=0;j<a[i];j++)
                c[j]=x;
            };
    return 0;
}
