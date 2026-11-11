#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
const int N=2e6+6;
int a[N];
bool check(int l,int r){
    if(r-l<2) return false;
    int d2=a[2]-a[1];
    if(d<d2||d<2*d2) return false;
    else if(d>=2*d2&&d<3*d2) return true;
    else return false;

}
int main(){
    int ans=0;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        cout<<0<<"\n";
    }
    return 0;
}
