#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    long long cnt=0;
    int j=n-1,i=0;
        while (i<=n/2&&j>=n/2&&j>i){
            if(c[i]==c[j]){
                a[i]--;
                a[j]--;
                if(a[i]==0)i++;
                if(a[j]==0)j--;
                continue;
            }
            if(a[i]==a[j]&&a[j]!=0){
                cnt+=a[i];
                i++;
                j--;
                continue;
            }
            if(a[j]!=0){
                a[j]--;
                a[i]--;
                if(a[i]==0)i++;
                if(a[j]==0)j--;
                cnt++;
                continue;
            }

            if(a[j]==0){
                j--;
                continue;
            }
        }
    cout<<cnt;
    return 0;
}
