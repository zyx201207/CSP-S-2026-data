#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,a[N],m,x=1,l=1,f,s=1;
bool cmp(int c,int d){
    return c<d;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    f=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    a[0]=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            x=max(i-l+1,x);
            s=i;
            continue;
        }
        if(m>=(i-l)*(a[i]-a[i-1])){
            m-=(i-l)*(a[i]-a[i-1]);
            x=max(i-l+1,x);
            s=i;
        }
        else{
            while(l<i||s==i){
                if(m<(i-l)*(a[i]-a[i-1])){
                    m+=a[s]-a[l];
                    l++;
                }
                else{
                    break;
                }
            }
            if(l==i||m<(i-l)*(a[i]-a[i-1])){
                l=i;
                m=f;
                s=i+1;
            }
            else if(m>=(i-l)*(a[i]-a[i-1])){
                s=i;
                m-=(i-l)*(a[i]-a[i-1]);
                x=max(i-l+1,x);
            }
        }
        //cout<<i<<" "<<x<<" "<<m<<" "<<l<<endl;
    }
    cout<<x<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
