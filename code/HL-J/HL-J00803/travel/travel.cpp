#include <bits/stdc++.h>

using namespace std;
long long c1,c2;
string s1,s2;
string ans;
string li1="DF",li2="ABC";
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    long long f1=li1.find(s1[2]),f2=li1.find(s2[2]);//li1
    long long f3=li2.find(s1[2]),f4=li2.find(s2[2]);//li2
    if(c1==c2){
        ans+='1';
        if(s1[0]==s2[0]){
            ans+='1';
            if((f1==-1&&f2==-1)||(f1!=-1&&f2!=-1)){
                ans+='1';
                if(f1==-1){
                	if((f3==f4+1)||(f3==f4-1)){
                		ans+='1';
					}else ans+='0';
				}else if(f1!=-1){
					if((f1==f2+1)||(f1==f2-1)){
						ans+='1';
					}else ans+='0';
				}
            }else ans+="00";
        }else ans+="000";
    }else ans+="0000";
    cout<<ans;
    return 0;
}
