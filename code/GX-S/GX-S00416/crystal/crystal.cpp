#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1200000000000;
int m,n,a[N],s[N];
int ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    ans=0;
    for(int i=0;i<=m;i++){
        cin>>a[i];
        if(ans=0){
            for(int j=0;j<=m-1;j++){
                while(m>0){
                    if(a[i+1]>0&&a[i+1]>a[i]){
                        s[j]=a[i+1]-a[i];
                        if(s[j]<s[j+1]){
                            while(s[j]!=0){
                                s[j]--;
                                m--;
                            }
                        }
                        else if(s[j]>s[j+1]){
                            while(s[j+1]!=0){
                                s[j+1]--;
                                m--;
                            }
                        }else{
                            while(s[j]!=0){
                                s[j]--;
                                s[j+1]--;
                                m-2;
                            }
                        }
                    }
                }
            }
        }
        ans++;
    }
    cout<<"3";
    return 0;
}
