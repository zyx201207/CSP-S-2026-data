#include<bits/stdc++.h>
using namespace std;
const int maxm=3e5+5;
int n,m,a[maxm],ans[maxm],s[maxm],tot=0;
bool flag[maxm];
int main(){
//    freopen("card.in","r",stdin);
//    freopen("card.out","w",stdout);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cout<<"it is "<<i<<endl;
        memset(flag,true,sizeof(flag));
        memset(s,0,sizeof(s));
        tot=0;
        for(int j=i;j<=n;j++){
            if(flag[a[j]]){
                s[j-tot]=a[j];
                cout<<"nows=";
                for(int o=1;o<=j;o++)cout<<s[o]<<",";
                cout<<endl;
                flag[a[j]]=false;
            }else{
                while(s[j-tot-1]==a[j]){
                    s[j-tot]=0;
                    cout<<"tot++="<<tot<<endl;
                    tot++;
                }
                cout<<"changes=";
                for(int o=1;o<=j;o++)cout<<s[o]<<",";
                cout<<endl;
            }
        }
        for(int j=1;j<=n-tot;j++)ans[s[j]]++;
        cout<<"ans=";
        for(int o=1;o<=m;o++)cout<<ans[o]<<",";
        cout<<endl;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
/*
luogu:Britney_Miku
08:34 CSP-J RP++
08:35 T1
08:39 T1 ? seems EZ details!
08:41 ice ice ice
09:00 T1 debug xiabiao boom
09:08 WTF SBprintf waste my 10min
09:11 911(? T1 maybe AC
09:12 T2
09:18 T2 baoli will boom
09:22 T2 youhua dp?->sb could TLE
09:52 T2 debug zenmeburangshuru
09:54 children I used int to cin char I am stuck
10:01 my fault I am stuck no idea so I forget to ans++
10:10 T2 over I think will TLE but 50pts leftandright
10:14 T2 bigin4 ac!?
10:16 T2 bigin5&6 boom in my thought
10:17 suanniao 50pts shuaqima T3 gogogo
10:20 WAITWAITWAIT WHY T3 DFS MAYBE 50PTS?
10:23 T3 maybe dp?I wonder that I could write both of them
10:26 zhuyidao youyigedian m=1 so if I am mankind I can take 5pts
10:31 dp->sb maybe fanhuitanxin? but I am thinking dfs
10:38 tanxin->rolling wood    dfs->bufenfen
10:57 T3 over I forget to declare d xixi
10:59 yo dfs even open wise!!!It did not boom in sample 1!!!
11:01 OK dfs has closed wise.The sample 2 was incorrect.DEBUG.
11:08 I AM TOO SB THAT I FORGET TO KEEP MY FLAG IN T3
11:25 WTF why my and do not work?
11:32 T3 broken I only could pass two simples.Why"&"!="and"(from timu)
11:36 bye bye T3
11:39 I have no time so T4 baoli
11:51 T4 over chunmoni bujieshi

*/
