#include <bits/stdc++.h>
using namespace std;
int r1,l1,r2,l2;
char a[2*(int)1e5+5];
long long a1[2*(int)1e5+5];
long long ans;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a1[i]>>a[i];
    }
    l1=a1[1],r1=a1[n];
    l2=1,r2=n;
    while(l2<=r2){
        if(a[l2]!=a[r2])    ans+=min(l1,r1);
        if(l1>r1){
            r2--;
            l1-=r1;
            r1=a1[r2];
        }
        else if(l1<r1){
            l2++;
            r1-=l1;
            l1=a1[l2];
        }
        else if(l1==r1){
            r2--;
            r1=a1[r2];
            l2++;
            l1=a1[l2];
        }
    }
    cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
