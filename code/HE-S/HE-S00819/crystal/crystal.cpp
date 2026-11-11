#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long num[500010];
long long num2[500010];
bool jisuan(long long n,long long sum,long long m){
    for(int i=0;i<n-sum+1;i++){
        if(num[i+sum-1]*sum-num2[i+sum]+num2[i]<=m){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>num[i];
        if(num[i]<0){
            num[i]*=-1;
        }
    }
    sort(num,num+1);
    for(int i=1;i<=n;i++){
        num2[i]=num[i-1]+num2[i-1];
    }
    int flag=1;
    long long sum=2;
    while(flag==1){
        if(jisuan(n,sum,m)){
            sum++;
        }else{
            if(sum==2){
                sum=0;
            }else{
                sum--;
            }
            flag=0;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
