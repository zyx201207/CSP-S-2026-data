#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,s[200005];
char c[200005];
long long int ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>c[i];
        }
        for(int i=1;i<=n;i++){
            int cnt=s[i],p=n;
            while(n!=0){
                if(s[p]>=cnt&&c[i]!=c[p]){ans+=cnt;s[p]-=cnt;break;}
                else if(s[p]<cnt&&c[i]!=c[p]){ans+=s[p];cnt-=s[p];s[p]=0;p--;}
                else if(s[p]<cnt&&c[i]==c[p]){cnt-=s[p];s[p]=0;p--;}
                else if(s[p]>=cnt&&c[i]==c[p]){s[p]-=cnt;break;}
            }
        }
        cout<<ans;
        return 0;
}
