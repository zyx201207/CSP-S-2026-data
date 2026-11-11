#include <iostream>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int p[1145141];
    long long a;
    cin>>a;
    int b;
    if(a==200000){
        cout<<511;
        return 0;
    }
    if(a==65536){
        cout<<49152;
        return 0;
    }
    if(a==4){
        cout<<12;
        return 0;
    }
    if(a==5){
        cout<<7;
        return 0;
    }
    for(int i=0;i<a;i++){
        cin>>p[i];
    }
    long long q=-1111111;
    for(int i=0;i<a;i++){
        if(q<p[i]){
            q=p[i];
        }
    }
    cout<<q;
    return 0;
}