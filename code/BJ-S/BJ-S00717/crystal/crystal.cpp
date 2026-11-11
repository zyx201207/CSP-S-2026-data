#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long m;
int a[1000000];
int ans;
int num;
char *r="read",*w="write";
int main(){
    freopen("crystal.in",r,stdin);
    freopen("crystal.out",w,stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=n;i>1;i--){
        unsigned long long t=m;
        int x=i-1;
        num=1;
        while(t){
            int k=a[i]-a[x];
            if(t>=k){
                t-=k;
                num++;

            }else{
                t=0;
            }
            x--;
            if(x<1){
                break;
            }
        }
        ans=max(num,ans);
    }
    cout<<ans;
return 0;
}
