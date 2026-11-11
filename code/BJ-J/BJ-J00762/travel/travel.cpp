#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//#define WZH_Local
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define foR(i,a,b) for(int i=(a);i>=(b);i--)
int t=1;
int a,b;
string str1,str2;
map<char,int>mp;
bool che(char ch1,char ch2){
    return (str1[2]==ch1&&str2[2]==ch2)||(str1[2]==ch2&&str2[2]==ch1);
}
int main(){
    #ifndef WZH_Local
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    #endif
    //cin>>t;
    while(t--){
        mp['A']=mp['B']=mp['C']=1;
        mp['D']=mp['F']=2;
        cin>>a>>str1>>b>>str2;
        // cout<<str1[2]<<' '<<str2[2]<<'\n';
        // cout<<mp[str1[2]<<' '<<mp[str2[2]]<<'\n';
        // cout<<boolalpha<<che('A','B')<<'\n';
        if(a!=b) cout<<"0000";
        else if(str1.substr(0,2)!=str2.substr(0,2)) cout<<"1000";
        else if(mp[str1[2]]!=mp[str2[2]]) cout<<"1100";
        else if(che('A','B')||che('B','C')||che('D','F')) cout<<"1111";
        else cout<<"1110";
    }
    return 0;
}//02 01A 02 01B
