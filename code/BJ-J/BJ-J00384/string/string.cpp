#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,res=0;
    cin>>n;
    char c[n+1];
    int num[n+1];
    for(int i=1;i<=n;i++) cin>>num[i]>>c[i];
    int l=1,r=n;
    while(l<r){
        int min=num[l]>num[r]?num[r]:num[l];
        num[l]-=min;
        num[r]-=min;
        if(c[l]!=c[r]) res+=min;
        //cout<<l<<' '<<r<<' '<<min<<' '<<res<<endl;
        if(num[l]) r--;
        else l++;
    }
    cout<<res;
    return 0;
}