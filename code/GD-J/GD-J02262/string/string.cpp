#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,num=0,sum=0;
    cin>>n;
    string st;
    for(long long i=0;i<n;i++){
        long long a;
        string c;
        cin>>a>>c;
        for (int j=0;j<a;j++){
            st+=c;
            num+=1;
        }
    }
    long long left=0,right=num-1;
    for (long long i=0;i<num/2;i++){
        if (st[left]!=st[right]){
            sum+=1;
        }
        left+=1;
        right-=1;
    }
    cout<<sum;
    return 0;
}
