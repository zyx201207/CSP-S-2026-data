#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N];
long long ans;
string s[N];
bool v[N];
void f(int a,int b){
    string sum;
    while(a){
        sum.push_back(char((a%2)+'0'));
        a/=2;
    }
    int x=sum.size();
    for(int i=0;i<x;i++){
        s[b].push_back(sum[x-i-1]);
    }
    return ;
}
long long pow(int a,int b){
    long long sum=1;
    while(b--){
        sum*=a;
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","s",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f(a[i],i);
    }
    int k=INT_MIN;
    for(int i=1;i<=n;i++){
        int x=s[i].size();
        k=max(x,k);
    }
    for(int i=1;i<=n;i++){
        while(s[i].size()<k){
            s[i]="0"+s[i];
        }
    }
    /*for(int i=1;i<=n;i++){
        cout<<s[i]<<endl;
    }*/
    for(int j=1;j<=k;j++){
        int sum=0;
        for(int i=1;i<=n;i++){
            if(s[i][j-1]=='1'&&v[i]!=1)sum++;
        }
        if(sum>=m){
            ans+=pow(2,k-j);
            for(int i=1;i<=n;i++){
                if(s[i][j-1]=='0')v[i]=1;
            }
        }
    }
    //for(int i=1;i<=n;i++){
    //    cout<<v[i]<<endl;
    //}
    cout<<ans;
    return 0;
}
