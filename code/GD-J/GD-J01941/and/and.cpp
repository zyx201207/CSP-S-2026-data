#include<bits/stdc++.h>
using namespace std;
long long a[200020];
int s[40];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        string k="";int x=a[i],o=0;
        while(x){
            s[o]+=x%2;
            x/=2;o++;
        }
    }
    sort(a+1,a+n+1);
    long long ans1=0,ans2=0,op=a[n],k=1;
    for(int i=n;i>=1;i--){
        op=op&a[i];
        if(k==m){
            ans1=max(op,ans1);
            k=0;
            op=a[i-1];
        }
        k++;
    }
    for(int i=0;i<31;i++){
        if(s[i]>=m){
            ans2+=pow(2,i);
        }
    }
    if(n*m<=100000 || m>1000) ans2=0;
    cout<<max(ans1,ans2);
    fclose(stdin);fclose(stdout);
    return 0;
}
