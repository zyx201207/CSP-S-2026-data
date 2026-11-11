#include<iostream>
#include<string>
using namespace std;

long long minn(long long a,long long b){

    if(a<b){
        return 1;
    }
    if(a==b){
        return 0;
    }
    return 2;
}

long long a[200000];// 数 字
string b[200000];//字 母

long long n;
long long co=0;
long long j=0;
long long k=3456;

long long chec(long long a[],string b[]){
    long long mj;

    if(j==k){
    return co;
    }
    mj=minn(a[j],a[k]);

    if(b[j]==b[k]){
        if(mj==0){
            j++;
            if(j==k){
            return co;
            }
            k--;
            return chec(a,b);
        }
        if(mj==1){
            a[k]-=a[j];
            j++;
            return chec(a,b);
        }
        if(mj==2){
            a[j]-=a[k];
            k--;
            return chec(a,b);
        }
    }
    if(mj==0){
        co+=a[j];
        j++;
        if(j==k){
        return co;
        }
        k--;
        return chec(a,b);
    }
    if(mj==1){
        co+=a[j];
        a[k]-=a[j];
        j++;
        return chec(a,b);
    }
    if(mj==2){
        co+=a[k];
        a[j]-=a[k];
        k--;
        return chec(a,b);
    }


}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    k=n-1;

    if(n==1){
        cout<<"0";
        return 0;
    }

    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }

    j=0;

    cout<<chec(a,b);

    return 0;
}
