/*
in:
3
2 a
2 b
1 c
out:
2
*/
#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int maxN=2e5+5;

int n,cnt;

int a[maxN];

char c[maxN];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    for(int i=1,j=n;i<j;){
        if(a[i]<a[j]){
            if(c[i]!=c[j]){
                cnt+=a[i];
            }
            a[j]-=a[i];
            i++;
        }else if(a[i]>a[j]){
            if(c[i]!=c[j]){
                cnt+=a[j];
            }
            a[i]-=a[j];
            j--;
        }else{
            if(c[i]!=c[j]){
                cnt+=a[i];
            }
            a[j]=0,a[i]=0;
            i++,j--;
        }
    }
    cout<<cnt;
    return 0;
}
