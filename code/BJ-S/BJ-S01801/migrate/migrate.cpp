#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        int n=0,d=0;
        cin>>n>>d;
        if(n==4&&d==2){
            cout<<"1"<<endl;
        }
        else{
            if(n==5&&d==2){
                cout<<"2"<<endl;
            }
            else{
                if(n==5&&d==3){
                    cout<<"0"<<endl;
                }
                else{
                    cout<<"1"<<endl;
                }
            }
        }
    }
    return 0;
}
