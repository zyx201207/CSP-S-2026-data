#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long m[200000];
string a,b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i]>>b;
        for(long long j=0;j<m[i];j++){
            a+=b;
        }
    }
    long long left=0,right=a.size()-1;
    while(left<right){
        if(a[left]==a[right]){
            left++;
            right--;
            continue;
        }else{
            left++;
            right--;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
