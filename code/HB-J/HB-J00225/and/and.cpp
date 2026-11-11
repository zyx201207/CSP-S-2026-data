#include <iostream>
#include <string>
using namespace std;
int and(string x){
    string b="";
    b+=(x-0 )%2;
    x/=2;
    
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string c[n];
    for(int a=0;a<n;a++){
    	cin>>c[a];
    	
    }
    sort(c,c+n);
    
    return 0;
}
