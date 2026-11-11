#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[500010];
signed main(void){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,mm;
    cin>>n>>mm;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    int answer=INT_MIN;
    for(int j=1;j<=n;j++){
        int m=mm;
        for(int i=j;i<n;i++){
            int c=(i-j+1)*(arr[i+1]-arr[i]);//改到下一块水晶所需的次数
            if(m<c){
                answer=max(answer,i-j+1);
                break;
            }
            else m-=c;
        }
    }
    cout<<answer;
    return 0;
}
