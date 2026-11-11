#include<bits/stdc++.h>
using namespace std;
int n,num[100086],b=0,l=1,r;
long long ans=0;
char a[100086],c[100086];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i]>>a[i];
    }r=n;
    while(l<r){
        if(num[r]<=0)r--;
        if(num[l]<=0)l++;
        if(a[l]!=a[r]&&num[l]==num[r])ans+=num[l];
        else if(a[l]!=a[r]&&num[l]!=num[r]){
            if(num[l]>num[r]){
                if(r-l==1){
                    ans+=num[r];
                    l++;
                    continue;
                }
                if(num[l]-num[r]){
                    int i=num[l]-num[r],j=0;
                    while(i>0&&r-j>0){
                        if(i-num[r-j]>=0)i=i-=num[r-j];
                        r--;
                        j++;
                    }ans+=num[l];
                }

            }if(num[l]<num[r]){
                ans+=num[l];
                if(num[r]-num[l]+num[r]>0){
                    num[r]-=num[l]-num[r];
                    l+=1;
                    continue;
                }
            }
        }
        l+=1;
        r-=1;
    }
    cout<<ans;
    return 0;
}
