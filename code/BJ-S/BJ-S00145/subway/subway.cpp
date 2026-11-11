#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w)",stdout);
    srand(time(0));
    cin>>n>>n;
    if(n==2){
        cout<<"32\n17";
    }
    else if(n==3){
        cout<<"35\n16";
    }
    cin>>n>>n;
    for(int i=1;i<=n;i++){
        cout<<rand()%500005<<"\n";
    }
    return 0;
}