#include<bits/stdc++.h>
using namespace std;

/*
struct Poker{
    long long x;
    string s;
};

Poker a[200005];
long long ans;
long long p[200005];*/

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
/*
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].s;
        ans+=a[i].x;
        p[i]=ans;
    }

    if(ans%2!=0){
        long long r=(ans+1)/2;
        for(int i=)
    }*/

    long long n;
    cin>>n;
    string s="";
    long long ans=0,r=0;
    long long a=0;
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        string y;
        cin>>y;
        for(int j=1;j<=x;j++){
            s+=y;
        }
        ans+=x;
    }
    if(ans%2==0){
        r=ans/2;
        for(int i=0,j=ans-1;i<r,j>=r;i++,j--){
            if(s[i]!=s[j])  a++;
            //cout<< a <<" ";
        }
    }
    else{
        r = (ans+1)/2;
        //cout<<r<<endl;
        for(int i=0,j=ans-1;i<r-1,j>=r;i++,j--){
            if(s[i]!=s[j])  a++;
            //cout<< a <<" ";
        }
    }

    cout<< a;

    return 0;
}
