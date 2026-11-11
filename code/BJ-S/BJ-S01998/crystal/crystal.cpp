/*
    我发现可以写中文
    但是我偏要写拼音
    解读愉快，陌生人
    hao nan a wo bu xiang xie
    wei shen me wo hai yao can jia CSP-S a
    wan quan bu hui zuo
    xian zai shi 15:51
    dan shi wo T1 zhi dui le qian liang ge yang li
    fang qi le
    wo yao wan project sekai
    wo yao wan phigros
    wo yao kan <<wo bu shi xi shen>>
    hao kun a
    393939393939393939393939393939393939393939393939393939393939393939393939393939(39*39?)(Miku?)
    (qi shi wo shi J zu na ge X X XXX)
    bei jing ba zhong mei li de xiao yuan~
    xin qin de yuan ding tuan jie de huo ban~
    dang de yu lu ba wo men jiao guan~
    ni shi wo men cheng zhang de yao lan~

    18:26 182699
*/
#include <bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    double per=0.0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        per+=a[i];
    }
    per/=n;
    sort(a+1,a+n+1);
    long long x=0;
    int id,cnt=0;
    bool flag=false;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=per&&flag==false)
        {
            if(double(a[i]-per)>double(per-a[i-1]))
            {
                x=a[i-1];
                id=i-1;
                cnt++;
                flag=true;
            }
            else
            {
                x=a[i];
                id=i;
                cnt++;
                flag=true;
            }
        }
        else if(a[i]==x) cnt++;
    }
    sort(a+1,a+id,greater<long long>());
    int i=1;
    while(m-x+a[i]>=0)
    {
        m=m-x+a[i];
        cnt++;
        //cout<<"a[i]=="<<a[i]<<" i=="<<i<<endl;
        i++;
        if(i==id) break;
    }
    //cout<<per<<" "<<x<<" "<<id<<" "<<i<<endl;
    cout<<cnt;
    return 0;
}


























































//13799































































































































































































//32999
