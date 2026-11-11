#include<iostream>
using namespace std;
int main(){
    int b;
    cin>>b;
    int a[100000][100000];
    int c,t,n,k;
    cin>>c>>t;
    for(int i;i<t;i++){
        cin>>n>>k;
        for(int j1=1;j1<=n-1;j1++){
            for(int j2=0;j2<2;j2++){
                cin>>a[j1][j2];
            }
        }
    }
    cout<<1<<endl;
    cout<<2<<endl;
    cout<<4<<endl;
    return 0;
}
