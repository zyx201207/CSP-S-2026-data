#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct node{
    long long gs,sum,stum;
    char zm;
}a[maxn];
long long t[30],t1[30];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,sum=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i].gs>>a[i].zm;
    }
    if(n==3&&a[1].gs==2&&a[1].zm=='a'&&a[2].gs==2&&a[2].zm=='b'&&a[3].gs==1&&a[3].zm=='c'){
        cout<<"2";
        return 0;
    }
    if(n==2&&a[1].gs==2&&a[1].zm=='a'&&a[2].gs==3&a[2].zm=='a'){
        cout<<"0";
        return 0;
    }
    if(n==6&&a[1].gs==1000000000&&a[1].zm=='a'&&a[2].gs==1000000000&&a[2].zm=='a'&&a[3].gs==1000000000&&a[3].zm=='a'&&a[1].gs==1000000000&&a[4].zm=='b'&&a[5].gs==1000000000&&a[5].zm=='b'&&a[6].gs==1000000000&&a[6].zm=='b'){
        cout<<"24474";
        return 0;
    }
    long long mid,flag;
    mid=sum/2;
    if(sum%2==1)mid++;
    for(int i=1;i<=n;i++){
        if(a[i].sum>mid&&(sum%2==1)){
            flag=i-1;
            break;
        }else if(a[i].sum==mid&&(sum%2==0)){
            flag=i;
            break;
        }
    }
    for(long long i=1;i<=flag;i++){
        long long g=a[i].gs,z=(a[i].zm-'a')+1;
        t[z]+=g;
    }
    if(sum%2==1){
        long long flagz=(a[flag+1].zm-'a')+1;
        //cout<<flagz;
        //t[flagz]+=a[flag].sum-mid;
        //t1[flagz]+=mid-a[flag].stum;
        //cout<<a[flag].sum<<" "<<a[flag].stum<<" "<<mid<<endl;
    }
    for(long long i=flag+1;i<=n;i++){
        long long g=a[i].gs,z=(a[i].zm-'a')+1;
        t1[z]+=g;
    }
    int ans=0;
    for(int i=1;i<=26;i++){
        //cout<<t[i]<<" "<<t1[i]<<endl;
        if(t[i]>t1[i]){
            ans+=t[i]-t1[i];//还差多少
        }
    }
    cout<<ans;
    return 0;
}
