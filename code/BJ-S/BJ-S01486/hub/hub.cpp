#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int t,d;
    cin>>t>>d;
    for(int i=1;i<=d;i++){
        cout<<i<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
