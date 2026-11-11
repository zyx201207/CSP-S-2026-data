#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+20;
int n,m;
ll a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll ans=a[n];
    cout<<a[n]<<" "<<a[n-1]<<" ";
    if(n==m)
    {
        ll ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans|=a[i];
        }
        cout<<ans<<"\n";return 0;
    }
    else if(m==1)
    {
        cout<<a[n]<<"\n";return 0;
    }
    for(int i=1;i<m;i++)
    {
        ans&=a[n-i];
        //cout<<"ans[n-"<<i<<"]="<<a[n-i]<<"   ans="<<ans<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}
//LuoTianYi NB!
//by Luogu@HuangRuibo uid:1286421  QwQ
//by BiliBili@HuangRuibo <-关注喵！
//555 CSP-J都好难喵 我是蒟蒻喵
//rp++;








































































/*xia xie de xian de mei shi+
#include<bits/stdc++.h>
using namespace std;
string gonggao1="Because a hacker let our website cannot work,so we have to use this shell to work.\nSorry   ------HAAVK IT\n\n";
string gonggao2="Because the shell cannot display Chinese well,so this work program is English(the LoginPage has got Chinese).\nSorry   ------HAAVK IT\n\n";
string nm="isPrime",psw="hvk&gti_isprime_2026_!@#$%^&*",key="usbkey";
int main()
{
    cout<<"Welcome to HAAVK !  \n欢迎来到 HAAVK !\n";
    lgin:
    cout<<"\n Login Page \n 登录\n";
    cout<<"\nUserName用户名:";
    string name;
    cin>>name;
    if(name==nm)
    {
        cout<<"\nPassword密码:";
        string pw;
        cin>>pw;
        if(pw==psw || pw==key)
        {
            cout<<"Welcome,isPrime! \n欢迎回来,isPrime!";
            cout<<"\n\n\n";
            cout<<gonggao1<<gonggao2;
            //cout<<"\n"<<"type in the number please(type \"list\" to display this list):"<<"  1.Home  "<<"2.UserPage"<<"\n";
            cout<<"type H4CK3R to let you like a hacker:";
            string h4ck3r;cin>>h4ck3r;
            if(h4ck3r=="H4CK3R")
            {
                cout<<"    WELCOME,[HACKER]"<<name<<"\n";
                cout<<"    I'M A HACKER IN G.T.I.\n";
                cout<<"    LETS PLAY A GAME! DO YOU WANT TO JOIN(Y/N)?"<<name<<"\n";
                char yn;cin>>yn;
                if(yn=='n' || yn=='N')
                {
                    cout<<"    SO BORING YOU ARE!SAY GOODBYE TO YOUR USERNAME AND PASSWORD!!\n";
                    nm="A_BORING_PEOPLE_IN_HAAVK";psw="faoweuh27328fgf*GF*GFE*&FGE)f0gefE(*fheg0a9erghaegfa048gfaru-rgvfbof]bpgjh,/.,gfh";//key="faoweuh27328fgf*GF*GFE*&FGE)f0gefE(*fheg0a9erghaegfa048gfaru-rgvfbof]bpgjh,/.,gfh";
                    cout<<"\n\n\n[SYSTEM]Something Error,Please Login Again.\n";
                    goto lgin;
                }
                else
                {
                    cout<<"   WoW!YOUR PASSWORD WILL BE MINE!!";
                    cout<<"\n\n\n[SYSTEM]Something Error.Turning on auto_fix_pro_3.0 ...\n10.34%\n56.26%\m67.67%\n100.00%";
                    cout<<"Fixing...";
                    nm="A_BORING_PEOPLE_IN_HAAVK";psw="faoweuh27328fgf*GF*GFE*&FGE)f0gefE(*fheg0a9erghaegfa048gfaru-rgvfbof]bpgjh,/.,gfh";//key="faoweuh27328fgf*GF*GFE*&FGE)f0gefE(*fheg0a9erghaegfa048gfaru-rgvfbof]bpgjh,/.,gfh";
                    for(int i=1;i<=500000;i++)
                    {
                        cout<<psw;
                    }
                    cout<<"\n\n\n[SYSTEM]Something Error,Please Login Again.\n";
                    goto lgin;
                }
            }
        }
        else
        {
            cout<<"#Err_001B:PSW_ISNT_RIGHT\nExit:-1\n";
            return 0;
        }
    }
    else
    {
        cout<<"#Err_001A:CANT_FIND_USER\nExit:-1\n";
        return 0;
    }
    return 0;
}
*/
