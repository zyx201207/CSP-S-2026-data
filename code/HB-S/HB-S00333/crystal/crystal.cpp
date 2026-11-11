#include<bits/stdc++.h>
using namespace std;
long long num[5000005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n;
    long long m;
    int cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];

    }
    if(n>5000)
    {
        int qiuhe=0;
        for(int i=1;qiuhe<m;i++)
        {
            qiuhe+=num[i];
            cnt++;
        }
        cout<<cnt;
        return 0;
    }
    sort(num+1,num+1+n);

    long long mx=-2147483648;
    long long m1=m;
    for(long long i=1;i<=n;i++)
    {
        long long j=1;
        long long cnt=1;
        m1=m;
        while(num[i]-num[i-j]<=m1&&i-j>=1)
        {
            m1-=(num[i]-num[i-j]);
            cnt++;
            j++;
        }
        mx=max(mx,cnt);
    }
    cout<<mx<<endl;
    return 0;
}
//wo de c++ sheng ya jiu zhe me jie shu le me? wo shen zhi mei you shi jian liu xia chang pian de liu yan
//suan le ba, cong jin tian yi hou, jiu mei you OIER ren shi wo le 
//zhe ji nian wo hao xiang xue le hen duo, dan shi you shen me dou mei xue
//gu ji shi xin si quan bu hua zai tou wan you xi shang le ba......
//5 nian OI yi chang kong, zui hou hai yao ji gao zhong, 
//cout<<"Goodbye_World";
//--Eggy_Hwang in luogu

//ha ha ha, xiao si wo le , ben lai hen shang gan de, dan shi wo pang bian de da ge hao xiang mei shan chu wen jian......
