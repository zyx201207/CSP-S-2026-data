#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],sum=0,ans=0;
char c[N];
string s;
bool flag=false;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i],sum+=a[i];
    int ssum=sum;
    if(sum%2==1) flag=1;
    sum/=2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=a[i];j++)
            s+=c[i];
    for(int i=ssum-1,j=0;i>=sum+flag;i--,j++){
        if(s[i]!=s[j]){
            ans++;
            s[i]=s[j];
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
}

/*O(nlogn)-->O(nL)
xiang le ban tian
xiang bu chu lai
guo duan fang qi
bao li qi dong!
yao bu shi yin wei shu ru fa...
*/
