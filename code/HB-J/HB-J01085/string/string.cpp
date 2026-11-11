#include <bits/stdc++.h>

using namespace std;
#define maxn 200005
long long asum,bsum,n,x,flag,num,sum,ans;
char c;
struct node{
    long long l,f;
}f[maxn],a[maxn],b[maxn];


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        num+=x;
        f[i].l=x;
        f[i].f=c-'a'+1;
    }
    for(int i=1;i<=n;i++){
        if(flag==0&&sum+f[i].l>=(num/2)){
            flag=1;
            if(num%2==1)
            {
                a[++asum].l=(num-1)/2-sum;

                a[asum].f=f[i].f;
                if(sum+f[i].l>(num+1)/2)
                {
                    b[++bsum].l=sum+f[i].l-(num+1)/2;
                    b[bsum].f=f[i].f;
                }
                else if(sum+f[i].l>(num/2))f[i+1].l--;
            }
            else{
                a[++asum].l=num/2-sum;
                a[asum].f=f[i].f;
                if(sum+f[i].l>num/2)
                {
                    b[++bsum].l=sum+f[i].l-num/2;
                    b[bsum].f=f[i].f;
                }

            }
        }
        else if(flag==0&&sum+f[i].l<(num/2)){
            sum+=f[i].l;
            a[++asum].l=f[i].l;
            a[asum].f=f[i].f;
        }
        else if(flag==1){
            b[++bsum].l=f[i].l;
            b[bsum].f=f[i].f;
        }
    }

    for(int i=1;i<=asum;i++)
    {
        while(b[bsum].l<=a[i].l){
            if(a[i].f!=b[bsum].f)ans+=b[bsum].l;
            a[i].l-=b[bsum].l;
            bsum--;
        }
        if(a[i].l!=0){
            if(a[i].f!=b[bsum].f){
                ans+=a[i].l;
                b[bsum].l-=a[i].l;
            }
        }

    }
    cout<<ans;
    return 0;
}
