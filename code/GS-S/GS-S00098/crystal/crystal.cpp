#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
unsigned long long n,m;
long long a[N];
int main(){
    freopen("crystal.in","r",stdin);//zhuyizheli
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int mx=0;
    sort(a+1,a+1+n);
    int cnt=1;
    int i=1,j=1;
    while(1){
        if(i>=n)break;
        if(m>=(a[i+1]-a[i])*cnt){
            m-=(a[i+1]-a[i])*cnt;
            cnt++;
            i++;
        }
        else{
            cnt--;
            m+=a[i]-a[j];
            j++;
        }
        if(cnt>mx)
        { 
            mx=cnt;
        }
    }
    cout<<mx;
    return 0;
}