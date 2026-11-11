#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int check(int x){
    int aa[300000]={};
    int num=0;
    int ans=0;
    while (x>=2){
        aa[num]=x%2;
        x=x/2;
        num+=1;
    }
    aa[num]=x;;
    for (int i=num;i>=0;i--){
        ans=ans*10;
        ans+=aa[i];
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxx=-1;
    if (m==1){
        for (int i=0;i<n;i++){
            if (a[i]>=maxx){
                maxx=a[i];
            }
        }
        cout<<maxx;
        return 0;
    }
    else if (m==2){
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if (check(a[i])&check(a[j]>maxx)){
                    cout<<a[i]<<" "<<a[j]<<endl;
                    maxx=check(a[i])&check(a[j]);
                }
            }
        }
        cout<<maxx;
        return 0;
    }
    return 0;
}
