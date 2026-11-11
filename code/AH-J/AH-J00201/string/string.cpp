#include<bits/stdc++.h>
using namespace std;
long long n,sum,ans;
long long a[200005];
string s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        sum+=a[i];
    }
    int m=(sum+1)/2;
    long long l=0,r=0,i=1,j=n;
    while(i<=j){
        if(s[i]!=s[j]){
            ans+=min(a[i]-l,a[j]-r);
        }
        if(a[i]-l<a[j]-r){
            r+=a[i]-l;
            l=0;
            i++;
        }else if(a[i]-l>a[j]-r){
            l+=a[j]-r;
            r=0;
            j--;
        }else{
            i++;
            j--;
            r=l=0;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
