#include<bits/stdc++.h>
using namespace std;
int x[2000006];
bool vi=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
        cin>>x[i];
    }
    int y[20005];
    for(int i=0;i<n;i++){
        if(abs(x[i]-x[i-1])<=d){
            vi=1;
        }
    }
    return 0;
}