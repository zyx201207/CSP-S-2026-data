#include<bits/stdc++.h>
using namespace std;
long long sum=0;
long long x[1000100];
char a[1000100];
string str="#";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>a[i];
        for(int j=1;j<=x[i];j++){
            str+=a[i];
        }
        sum+=x[i];
    }
    long long l=(sum+1)/2,r=(sum+2)/2,cnt=0,cnti=0;
    for(int i=1;i<=n;i++){
        cnt+=x[i];
        if(cnt>=x[i]){
            cnti=i;
            break;
        }
    }
    cnt=0;
    while(l>=1&&r<=sum){
        if(str[l]!=str[r]){
            cnt++;
        }
        l--;
        r++;
    }
    cout<<cnt<<endl;
    return 0;
}
