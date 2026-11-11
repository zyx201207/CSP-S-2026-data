#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
struct crystal{
    int num,sum1,x_1[50005],sum2,x_2[50005],pre=2147483647;
    bool flag=true,flag2=true;
}a[5005];
bool cmp1(crystal x,crystal y){
    return x.num<y.num;
}
bool cmp2(crystal x,crystal y){
    if(x.sum1!=y.sum1)
        return x.sum1>y.sum1;
    else if(x.sum2!=y.sum2)
        return x.sum2>y.sum2;
    else if(abs(x.pre)!=abs(y.pre))
        return abs(x.pre)<abs(y.pre);
    else
        return x.num>y.num;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i].num;
    sort(a+1,a+n+1,cmp1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if(a[i].flag==true&&a[j].flag==true){
                if(a[i].num==a[j].num){
                    a[i].x_1[++a[i].sum1]=j;
                    //cout<<a[i].num<<" "<<a[j].num<<endl;
                    if(a[i].sum1%2==1)
                        a[j].flag=false;
                    a[i].num*=2,a[i].sum1=0;
                    if(a[i].flag2==true)
                        ans++,a[i].flag2=false;
                    if(a[j].flag2==true)
                        ans++,a[j].flag2=false;
                    j--;
                    continue;
                }
                if(2*(a[i].num)==a[j].num)
                    a[i].x_2[++a[i].sum2]=j;
            }
        }
    for(int i=1;i<=n;i++)
        if(a[i].flag==true){
            int x=i+1;
            while(x<=n){
                if(a[x].flag==true)
                    //cout<<a[x].num<<" "<<a[i].num<<endl;
                    if((a[x].sum1%2)!=1){
                        a[i].pre=a[x].num-a[i].num;
                        break;
                    }
                x++;
            }
        }
    sort(a+1,a+n+1,cmp2);
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        if(a[i].flag==true)
            if(m>=a[i].pre){
                a[i].num+=a[i].pre;
                for(int j=1;j<=n;j++)
                    if(a[j].flag==true&&a[i].num==a[j].num){
                        a[j].flag=false;
                        if(a[i].flag2==true)
                            ans++,a[i].flag2=false;
                        if(a[j].flag2==true)
                            ans++,a[j].flag2=false;
                        a[i].num*=2;
                        a[j].pre=2147483647;
                        int x=i+1;
                        while(x<=n){
                            if(a[x].flag==true)
                                if((a[x].sum1%2)!=1){
                                    a[i].pre=a[x].num-a[i].num;
                                break;
                            }
                            x++;
                        }
                    }
            }
            sort(a+1,a+n+1,cmp2);
    }
    cout<<ans;
    //for(int i=1;i<=n;i++)
        //if(a[i].flag==true){
            //cout<<a[i].num<<" "<<a[i].sum1<<" "<<a[i].sum2<<" "<<a[i].pre<<endl;
        //}
    return 0;
}
