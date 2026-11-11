#include <bits/stdc++.h>
using namespace std;
//test:AC AC AC AC WA AC
const int N = 2e5+7;
int n,a[N];
char c[N];
long long int pre[N],sum,mid,ans;

int query(long long int x,int l,int r){//pair<<index>,<is_mid?>>
    if(l==r)return l;
    int mid = (l+r)/2;
    if(x<pre[mid+1])return query(x,l,mid);
    else return query(x,mid+1,r);
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    pre[1] = 1;
    for(int i = 1;i<=n;i++){
        cin >> a[i] >> c[i];
        pre[i+1] = pre[i]+a[i];
    }
    sum = pre[n+1]-1,mid = sum/2+sum%2;
    int p = query(mid,1,n);
    n++;
    for(int j = n;j>=p+1;j--){
        a[j] = a[j-1];
        pre[j] = pre[j-1];
        c[j] = c[j-1];
    }
    pre[n+1] = sum+1;
    a[p] = mid-pre[p]+1;
    a[p+1] = pre[p+1]-mid-1;
    c[p+1] = c[p];
    pre[p+1] = mid+1;
    if(pre[p+1]<pre[p])p--;
/*    for(int i = 1;i<=n;i++){
        printf("[%lld-%lld] %c\n",pre[i],pre[i+1]-1,c[i]);
    }
    cout << "[p]" << p << endl;*/
    for(int i = 1;i<=p;i++){
//        printf("[%d]",i);
        long long int y = sum+1-pre[i],x = sum+2-pre[i+1];//sum+2-pre[i+1] = sum+1-(pre[i+1]-1)
        int l = query(x,1,n),r = query(y,1,n);
//        cout << x << " " << y << " " << l << " " << r << " ";
        for(int j = l;j<=r;j++){
            if(c[i]!=c[j]){
                if(l==r)ans+=a[i];
                else if(j==l)ans+=pre[j+1]-x;//pre[j+1]-x = pre[j+1]-1-x+1
                else if(j==r)ans+=y-pre[j]+1;
                else ans+=a[j];
            }
        }
//        cout << ans << endl;
    } 
    printf("%lld",ans);
    return 0;
}