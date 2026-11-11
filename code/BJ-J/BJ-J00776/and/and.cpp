#include<bits/stdc++.h>
using namespace std;
int a[200050];
string s[200050];
int sum[35];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    int n,m,num=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int p=n;
    for(int i=30;i>=0;i--){
        sort(a+1,a+p+1,cmp);
        int k=pow(2,i),j=1,sum=0;
        while(a[j]>=k && j<=p){
            sum++;
            a[j]-=k;
        }
        if(sum>=m){
            num+=k;
            p=sum;
        }
    }
    cout<<num;
    return 0;
}
