#include<bits/stdc++.h>
using namespace std;
long long sum;
long long cnt;
int n, x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    cin>>n;
    char y;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        for(int i=1;i<=x;i++){
            sum++;
            s[sum]=y;
        }
    }
    long long mid=sum/2;
    if(sum%2==0){
        long long l=mid, r=mid+1;
        while(l>0){
            if(s[l]!=s[r])
                cnt++;
            l--;
            r++;
        }
    }
    else{
        long long l=mid, r=mid+2;
        while(l>0){
            if(s[l]!=s[r])
                cnt++;
            l--;
            r++;
        }
    }
    cout<<cnt;
    return 0;
}
