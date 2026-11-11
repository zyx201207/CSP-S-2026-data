#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long j=n,l=a[1],r=a[n],i=1;
    long long sum=0;
    while(i<j){
        if(b[i]==b[j]){
            if(l==r){
                i++;j--;
                l=a[i],r=a[j];
            }
            else if(l<r){
                i++;l=a[i];
                r-=a[i-1];
            }
            else{
                j--;r=a[j];
                l-=a[j+1];
            }
        }
        else{
            if(l==r){
                sum=(sum+a[i])*1ll;
                i++;j--;
                l=a[i],r=a[j];
            }
            else if(l<r){
                sum=(sum+l)*1ll;
                r-=l;
                i++;l=a[i];
            }
            else{
                sum=(sum+r)*1ll;
                l-=r;
                j--;r=a[j];
            }
        }
    }
    cout<<sum;
    return 0;
}

