#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    long long n,sum=0,ans=0;
    cin>>n;
    vector<long long>a(n);
    vector<char>b(n);
    for(long long i=0;i<n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    char s[sum];
    for(long long i=0;i<n;i++){
        for(long long j=0;j<a[i];j++){
            for(long long k=0;k<sum;k++){
                s[sum]=b[j];
            }
        }
    }
    long long left=0;
    long long right=n-1;
    while(left<=right){
        if(s[left]==s[right]){
            left++;
            right--;
        }else{
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
