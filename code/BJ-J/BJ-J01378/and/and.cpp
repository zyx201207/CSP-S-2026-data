#include<bits/stdc++.h>
using namespace std;
int zhuan(int a){
    int n=a,i=0;
    string s;
    long long sum=0;
    while(n>0){
        if(n%2==0){s[i]='0';i++;}
        else {s[i]='1';i++;}
        n/=2;
    }
    for(int j=i-1;j>=0;j--){
        sum=sum*10+(s[j]-'0');
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n]={0};
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);


    if(m==1){
        cout<<a[n-1];
        return 0;
    }

    for(int i=n-1;i>=0;i--){
        if(a[i]==a[i+1]){
            cout<<a[i];
            return 0;
        }
    }

    long long s1,s2,maxn=-1,sum=0,x;
    for(int i=0;i<n-1;i++){
        for(int j=i+1,p=0;j<n;j++,p=0,sum=0){
            s1=zhuan(a[i]);
            s2=zhuan(a[j]);
            while(s1>0||s2>0){
                if(s1%10==1&&s2%10==1){
                    sum+=pow(2,p);
                }
                p++;
                s1/=10;
                s2/=10;
            }
            maxn=max(maxn,sum);
        }
    }
    cout<<maxn;
    return 0;
}
