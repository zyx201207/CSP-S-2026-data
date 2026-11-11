#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
char c[N];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
int ans=0;
long long sum=1;
for(int i=1;i<=n;i++){
    int a;
    cin>>a;
    char b;
    cin>>b;
    for(int j=sum;j<sum+a;j++){
        c[j]=b;
    }
    sum+=a;
}

sum=sum-1;
int sum_3=sum;
int sum_2=sum/2+1;
for(int j=1;j<sum_2;j++){
        if(c[j]==c[sum_3]){
            sum_3--;
            continue;
        }else {
            ans++;
            sum_3--;
             continue;
        }
        if(sum_3-1==sum_2&&j==sum_2-1){
            break;

        }
    }



cout<<ans;
return 0;

}
