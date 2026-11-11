#include<bits/stdc++.h>
using namespace std;
vector<int> a[35];
int number[200005];
int num[200005];
int in;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&number[i]);
    }
    sort(number+1,number+1+n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            if(number[i]&(1<<j)){
                a[j].push_back(number[i]);
            }
        }
    }
    long long ans=0;
    for(int i=30;i>=0;i--){
        if(a[i].size()>=m){
            if(in==0){
                for(int j=0;j<a[i].size();j++){
                    num[j+1]=a[i][j];
                }
                in=a[i].size();
                ans=(1<<i);
            }else{
                int in2=0;
                for(int j=0;j<a[i].size();j++){
                    int l=in2,r=in+1;
                    while(l+1<r){
                        int mid=(l+r)/2;
                        if(num[mid]<=a[i][j]){
                            l=mid;
                        }else{
                            r=mid;
                        }
                    }
                    if(num[l]==a[i][j]){
                        num[++in2]=a[i][j];
                    }
                }
                in=in2;
                if(in>=m){
                    ans+=(1<<i);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
