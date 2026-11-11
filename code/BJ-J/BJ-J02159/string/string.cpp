#include<bits/stdc++.h>
using namespace std;
int s[200005][2];
long long x;
int r,l,ans,n;
char b;
int main(){
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    cin>>n;
    r=n-1;
    for(int i=0;i<n;i++){
        cin>>x>>b;
        s[i][0]=x;
        s[i][1]=b-'0';
    }
    while(l<r){
        if(s[l][1]==s[r][1]){
            if(s[l][0]>s[r][0]){
                s[l][0]-=s[r][0];
                r--;
            }
            else if(s[l][0]<s[r][0]){
                s[r][0]-=s[l][0];
                l++;
            }
            else{
                l++;
                r--;
            }
        }
        else{
            if(s[l][0]>s[r][0]){
                s[l][0]-=s[r][0];
                ans+=s[r][0];
                r--;
            }
            else if(s[l][0]<s[r][0]){
                s[r][0]-=s[l][0];
                ans+=s[l][0];
                l++;
            }
            else{
                ans+=s[r][0];
                l++;
                r--;
            }
        }

    }
    cout<<ans;
    return 0;
}
