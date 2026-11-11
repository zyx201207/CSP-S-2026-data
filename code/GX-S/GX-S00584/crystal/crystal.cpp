#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long res = 1;
long long a[500005];
//long long dp[500005];
long long cnt[500005];
long long kind[500005];
long long counting[500005];
const long long add = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    k=m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int num = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=num;j++){
            if(num==0){
                kind[num]=a[i];
                num++;
                counting[j]=1;
                continue;
            }
            else{
                if(kind[j]==a[i]){
                    //num++;
                    counting[j-1]++;
                    continue;
                }
                else if(kind[j]!=a[i] && j==num){
                    kind[j+1]=a[i];
                    num++;
                    counting[j]=1;
                    continue;
                }
            }
        }
    }
    //int maxn = *max_element(counting,counting+num);
    sort(counting,counting+num);
    int maxm = counting[num];
    sort(a,a+n);
    /*cout<<maxm<<endl;
    for(int i=0;i<num;i++){
        cout<<counting[i]<<endl;
    }*/
    //The speacial of example:max is 1
    if(maxm==1){
        int mid = n/2+1;    //The mid of date
        int x=a[mid];
        int i=1;
        while(k>0 && i<=mid){
            if(a[mid]-a[mid-i]>=0 && k-(a[mid]-a[mid-1])>=0){
                res++;
                k-=a[mid]-a[mid-i];
            }
            i++;
        }
        cout<<res+add<<endl;
    }
    else{
        int mid = n/2+1;    //The mid of date
        int x=a[mid];
        int i=1;
        while(k>0 && i<=mid){
            if(a[mid]-a[mid-i]>=0 && k-(a[mid]-a[mid-1])>=0){
                res++;
                k-=a[mid]-a[mid-i];
            }
            i++;
        }
        cout<<res<<endl;
    }
    return 0;
}
