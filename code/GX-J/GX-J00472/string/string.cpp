#include<bits/stdc++.h>
using namespace std;

int a[200010];
char c[200010];
int n;
string s;

int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>n;
    long long sum=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            s+=c[i];
        }
    }
    int l=1,r=sum;
    while(l<=r){
        if(s[l]!=s[r]) ans++;
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
