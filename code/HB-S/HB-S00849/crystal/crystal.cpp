#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,cnt=1,flag=0,j=0,maxcnt=0;
    cin>>n>>m;

    long long x=(n-1)*n/2;
    for(int i=0;i<n;i++) cin>>a[i];

    if(a[n-1]-a[0]==n-1&&m-x>=0){
        if((m-x)%n==0) cout<<n<<endl;
        else cout<<n-1<<endl;
        return 0;
    }

    long long y=n*(n-1)/2*(a[1]-a[0]);
    if((a[n-1]-a[0])%(n-1)==0&&m-y>=0){
        if((m-y)%n==0) cout<<n<<endl;
        else cout<<n-1<<endl;
        return 0;
    }


    for(int i=0;i<m;i++){
        sort(a,a+n);
        a[0]++;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";

    while(j<n){
        flag=j;
        j++;
        cnt=1;
        while(1){
            if(a[j]==a[flag]){
                j++;
                cnt++;
            }
            else{
                maxcnt=max(cnt,maxcnt);
                break;
            }
            if(j==n-1){
                cout<<cnt<<endl;
                return 0;
            }
        }
    }
    cout<<maxcnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
