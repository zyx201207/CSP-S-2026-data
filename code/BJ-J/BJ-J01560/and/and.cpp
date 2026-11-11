#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long aa[200005];
bool pass[200005];
string erjinzhi[200005];
string erjinzhi_qufan(long long x)
{
    string er;
    while(x!=0)
    {
        if(x%2==0)
        {
            er+='0';
        }
        else if(x%2==1)
        {
            er+='1';
        }
        x/=2;
    }
    return er;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int erjinzhi_max_size=-1;
    for(int i=1,j=n;i<=n;i++,j--)
    {
        aa[i]=a[j];
        erjinzhi[i]=erjinzhi_qufan(aa[i]);
        int sizeeeeee=erjinzhi[i].size();
        erjinzhi_max_size=max(erjinzhi_max_size,sizeeeeee);
    }
    string zuizhongchuan="";
    int erjinzhi_max_xiabiao=erjinzhi_max_size-1;
    //
    //for(int i=1;i<=n;i++)
    //{
    //    cout<<erjinzhi[i]<<endl;
    //}
    for(int i=erjinzhi_max_xiabiao;i>=0;i--)//遍历下标(需要的长度=当前下标+1)
    {
        int can_count=0;
        int yi_count=0;
        for(int j=1;j<=n;j++)//遍历字符串
        {
            if(erjinzhi[j].size()>=i+1&&pass[j]==false)
            {
                can_count++;
                if(erjinzhi[j][i]=='1')
                {
                    yi_count++;
                }
            }
        }
        //cout<<can_count<<" "<<yi_count<<endl;
        if(can_count<m||yi_count<m)
        {
            zuizhongchuan+='0';
            continue;
        }
        else if(yi_count>=m)
        {
            zuizhongchuan+='1';
            for(int j=1;j<=n;j++)
            {
                if(erjinzhi[j][i]=='0'||erjinzhi[j].size()<i+1)//如果这个字符串该位为0或长度不足，直接pass掉
                {
                    pass[j]=true;
                }
            }
        }
    }
    int zuizhongzhi=0;
    int weiquan=1;
    for(int i=zuizhongchuan.size()-1;i>=0;i--)
    {
        if(zuizhongchuan[i]=='1')
        {
            zuizhongzhi+=weiquan;
        }
        weiquan*=2;
    }
    cout<<zuizhongzhi;
    return 0;
}
