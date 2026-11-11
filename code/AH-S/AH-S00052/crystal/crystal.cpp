#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef int I;
I n,m,mid,m_num,l,r,p,sum=0;
LL a[500001]={};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;

    if(n%2==0) mid=n/2;    //quzhong
    if(n%2==1) mid=(n/2)+1;

    for(I i=1;i<=n;i++)cin>>a[i];

    for(I i=1;i<=n;i++){
        for(I j=i;j<=n;j++){    //paixu
            if(a[j]<a[i]){
                swap(a[i],a[j]);
            }
        }
    }
    m_num=a[mid];
    l=mid-1;
    r=mid+1;
    for(I i=1;i<=mid;i++){
        if(m==0)continue;
        if(l==0&&r==n)continue;
        if(m_num-a[l]<=a[r]-m_num){
            if(m-(m_num-a[l])<0)continue;
            p=m_num-a[l];
            m-=p;
            a[l]=m_num;
            if(l!=0)l--;
        }
        if(m_num-a[l]>=a[r]-m_num){
            if(m-(a[r]-m_num)<0)continue;
            p=a[r]-m_num;
            m-=p;
            a[r]=m_num;
            if(r!=n+1)r++;
        }
        if(a[l]==m_num) l--;
        if(a[r]==m_num) r++;
        if(l==0&&r<=n){
            while(r!=n+1){
                if(m-(a[r]-m_num)<0)continue;
                else{
                    p=a[r]-m_num;
                    m-=p;
                    a[r]=m_num;
                    r++;
                }
            }
        }
        if(l>=0&&r==n){
            while(l!=0){
                if(m-(m_num)-a[l]<0)continue;
                else{
                    p=m_num-a[l];
                    m-=p;
                    a[l]=m_num;
                    l--;
                }
            }
        }
    }
    for(I i=1;i<=n;i++){
        if(a[i]==m_num){
            sum++;
        }
    }
    cout<<sum<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
    }
