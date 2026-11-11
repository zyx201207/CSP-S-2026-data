#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e9;
const long long MAXL=1e5+5;
int n;
long long a[MAXL][2];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        char x;
        cin>>a[i][0]>>x;
        a[i][1]=(int)x;
    }
    long long cnt=0;
    for(int i=0,j=n-1;i<j;){
        if(a[i][1]!=a[j][1]){
            cnt+=min(a[i][0],a[j][0]);
            if(a[i][0]>a[j][0]){
                a[i][0]-=a[j][0];
                j--;
            }
            else if(a[i][0]<a[j][0]){
                a[j][0]-=a[i][0];
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        else{
            if(a[i][0]>a[j][0]){
                a[i][0]-=a[j][0];
                j--;
            }
            else if(a[i][0]<a[j][0]){
                a[j][0]-=a[i][0];
                i++;
            }
            else{
                i++;
                j--;
            }
        }
    }
    cout<<cnt;
    return 0;
}
