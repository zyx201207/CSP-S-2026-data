//GZ-J00231,遵义市第十二中学,韩冰洁
#include<bits/stdc++.h>
using namespace std;
int n,a[10000];
string s,x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i-1];
    }
    int num=0;
    for(int i=n;i>=1;i--){
        for(int j=num;j<num+a[i];j++){
            x[j]==s[n-i];
        }
        num+=a[i];
    }
    int sum=0;
    if(num%2==0){
        int l=num/2-1,r=num/2;
        for(int i=1;i<=num/2;i++){
            if(x[l]!=x[r]){
                sum++;
            }
            l-=1;
            r++;
        }
        cout<<sum;
    }
    else{
        int L=(num-1)/2-1,R=L+2;
        for(int i=1;i<=(num-1)/2;i++){
            if(x[L]!=x[R]){
                sum++;
            }
            L-=1;
            R++;
        }
        cout<<sum+1;
    }
    return 0;
}
