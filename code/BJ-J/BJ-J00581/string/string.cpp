#include<bits/stdc++.h>
using namespace std;
long long s[200001];
char x[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    long long cnt=0;
    cin>>a;
    for(int i=1;i<=a;i++){
        long long n;
        char c;
        cin>>n>>c;
        s[i]=n;
        x[i]=c;
    }
    int left=1,right=a;
    while(left<right){
        if(x[left]!=x[right]){
            cnt+=min(s[left],s[right]);
        }
        if(s[left]==s[right]){
            left++;
            right--;
        }
        else if(s[left]<s[right]){
            s[right]-=s[left];
            left++;
        }
        else{
            s[left]-=s[right];
            right--;
        }
    }
    cout<<cnt;
    return 0;
}
