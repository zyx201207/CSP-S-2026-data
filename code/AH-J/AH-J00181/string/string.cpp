#include<bits/stdc++.h>
using namespace std;
int n,pos,flag;
long long sum,num,ans,a[200005];
char ch[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x;
        cin>>c;
        if(c==ch[pos]){
            a[pos]+=x;
        }
        else{
            pos++;
            a[pos]=x;
            ch[pos]=c;
        }
        sum+=x;
    }
    if(sum%2)flag=1;
    sum/=2;
    int i=1,j=pos;
    while(i<=j)
    {
        num+=a[i];
        long long s=a[i];
        if(num>sum)
        {
            int r=num-sum-flag;
            int l=a[i]-r-flag;
            s=l-r;
            if(s<=0)break;
        }
        while(i<=j)
        {
            if(ch[j]==ch[i])
            {
                if(a[j]>s)
                {
                    a[j]-=s;
                    s=0;
                }
                else
                {
                    s-=a[j];
                    j--;
                }
            }
            else
            {
                if(a[j]>s)
                {
                    a[j]-=s;
                    ans+=s;
                    s=0;
                }
                else
                {
                    s-=a[j];
                    ans+=a[j];
                    j--;
                }
            }
            if(s==0)
                break;
        }
        i++;
    }
    cout<<ans;
    return 0;
}
