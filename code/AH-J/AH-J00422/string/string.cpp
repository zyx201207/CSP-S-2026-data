#include<bits/stdc++.h>
using namespace std;
long long s1[200010];
char s2[200010];
long long ans;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    int l=1,r=n;
    while(l<r){
        if(s2[l]!=s2[r]){
            if(s1[l]-s1[r]>0){
                ans+=s1[l]-s1[r];
                s1[l]-=s1[r];
                r--;
            }
            else if(s1[l]==s1[r]){
                ans+=s1[l];
                l++;
                r--;

            }
            else{
                ans+=s1[r]-s1[l];
                l++;
                s1[r]-=s1[l];
            }
        }

        else{
            if(s1[l]>s1[r]){
                s1[l]-=s1[r];
                r--;
            }
            else if(s1[l]==s1[r]){
                l++;
                r--;
            }
            else{
                s1[r]-=s1[l];
                l++;
            }
        }
    }

cout<<ans;
    return 0;
}
