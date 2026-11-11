#include<bits/stdc++.h>
using namespace std;
long long n,adx,ans[15],k=1,t;
char s[100000005];
long long s2[200005];
bool flag=false;
int main(){
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        cin>>s2[i]>>s[i];
    }
    for(int i=1;i<=n/2;i++){
        if(s[i]!=s[n+1-i]){
            if(s2[i]>s2[n+1-i]){
                s2[n-i]-=s2[i]-s2[n+1-i];
                if(s[n-i]==s[i]){
                    t=s2[n+1-i];
                    while(t){
                        ans[k]+=t%10;
                        ans[k+1]+=ans[k]/10;
                        t/=10;
                        k++;
                    }
                    k=1;
                }else{
                    t=s2[i];
                    while(t){
                        ans[k]+=t%10;
                        ans[k+1]+=ans[k]/10;
                        t/=10;
                        k++;
                    }
                    k=1;
                }
            }else if(s2[i]<s2[n+1-i]){
                s2[i+1]-=s2[n+1-i]-s2[i];
                if(s[n-i+1]==s[i+1]){
                    t=s2[i];
                    while(t){
                        ans[k]+=t%10;
                        ans[k+1]+=ans[k]/10;
                        t/=10;
                        k++;
                    }
                    k=1;
                }else{
                    t=s2[n-i+1];
                    while(t){
                        ans[k]+=t%10;
                        ans[k+1]+=ans[k]/10;
                        t/=10;
                        k++;
                    }
                    k=1;
                }
            }else{
                t=s2[i];
                    while(t){
                        ans[k]+=t%10;
                        ans[k+1]+=ans[k]/10;
                        t/=10;
                        k++;
                    }
                    k=1;
            }
        }
    }
    for(int i=15;i>=1;i--){
        if(ans[i]==0 && flag==false){
        }else{
            cout<<ans[i];
            flag=true;
        }
    }
    if(flag==false) cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

