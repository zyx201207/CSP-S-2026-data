#include<algorithm>
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
using namespace std;
string ss;
int main(){
    freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    long long n,a[200005],ans=0,cnt=0;
    char c[200005];
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1,j=n;i<=j,j>=i;i++,j--){
        if(c[i]!=c[j]){
            if(a[i]==a[j]){
                ans+=a[i];
            }
            else if(a[i]<a[j]){
                a[j]-=a[j]-a[i];
                ans+=a[i];
                j++;
            }
            else{
                a[i]-=a[i]-a[j];
                ans+=a[j];
                i--;
            }
        }
    }
    cout<<ans;
    return 0;
}
