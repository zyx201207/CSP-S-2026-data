#include <bits/stdc++.h>
using namespace std;
int a[100000005];
char c[100000005];
int n;
string s;
int main(){
    freopen("string .in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
    }
    int sum=0,cnt=0;
    for(int i=1;i<=n;i++){
        sum += a[i];
    }
    for(int i=1;i<=n,i++){
        for(int j=1;j<=a[i];j++){
            s += c[i];
        }
    }
    int r=0,l=sum;
    for(int i=1;i<=sum/2;i++){
        int mid=(r+l)/2;
        if(mid%2!=0){
            if(s[mid-1]==s[mid+1]){
                r=mid-1;
                l=mid+1;
            }
            else{
                s[l]=s[r];
            }
            for(int i=1;i<=sum/2;i++){
                if(s[mid-1]==s[mid+1]){
                    r-=1;
                    l+=1;
                }
                else{
                s[l]=s[r];
                }
            }
        }
    }
    for(int i=1;i<=sum;i++){
        cout <<s[i];
    }
    return 0;
}
