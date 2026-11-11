#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+5;
int a1[N],a2[N];
char c1[N],c2[N];
int n;
ll ans;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a1[i]>>c1[i];
    }
    //反转输入d
    for(int i=1;i<=n;i++)
    {
        a2[i]=a1[n-i+1];
        c2[i]=c1[n-i+1];
    }
    //****************************
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<a2[i]<<" ";
    // }
    // cout<<"\n";
    for(int i=1,j=1; i<=n;)
    {
        //i,j分别为第几个元组
        // cout<<"i="<<i<<" j="<<j<<" ";
        if(c1[i]==c2[j])
        {
            // cout<<"a1[i]="<<a1[i]<<" a2[j]="<<a2[j]<<" c1[i]="<<c1[i]<<" c2[i]="<<c2[j];
            // cout<<"相同\n";
            int k=min(a1[i],a2[j]);
            a1[i]-=k;
            a2[j]-=k;
            if(a1[i]==0)
            {
                i++;
            }
            if(a2[j]==0)
            {
                j++;
            }
        }
        else
        {

            // cout<<"a1[i]="<<a1[i]<<" a2[j]="<<a2[j]<<" c1[i]="<<c1[i]<<" c2[j]="<<c2[j];
            // cout<<"不相同\n";
            int k=min(a1[i],a2[j]);
            ans+=k;
            a1[i]-=k;
            a2[j]-=k;
            if(a1[i]==0)
            {
                i++;
            }
            if(a2[j]==0)
            {
                j++;
            }
        }
    }

    //**************************
    cout<<ans/2;
    return 0;

    fclose(stdin);
    fclose(stdout);
    /*
    思路：
    1.将输入反转，得到类似[(a,b),(a,b)]的输入（数量，字符）
    2.将每个输入进行遍历，对比反转和未反转的数量较少的字符串。
        如果字符相同，则删去相同的字符串。
        如果不同，则答案+=不同的数量，删去比对完成的字符串
    3.将答案/2输出
    */
}
