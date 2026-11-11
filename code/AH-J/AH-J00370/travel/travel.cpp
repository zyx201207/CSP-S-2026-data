#include<bits/stdc++.h>
using namespace std;
long long n1,n2;
string s1,s2;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n1>>s1>>n2>>s2;
    if(n1==n2){
        cout<<'1';
        if((s1[0]==s2[0]&&s1[1]==s2[1])){
            cout<<'1';
            int l1=s1[2],l2=s2[2];
            if((l1=='A'||l1=='C'||l1=='B')&&(l2=='A'||l2=='C'||l2=='B')||((l1=='F'||l1=='D')&&(l2=='D'||l2=='F'))){
                cout<<'1';
                if(l1=='D'||l1=='F'||abs(int(l1-l2)<2)){
                    cout<<'1';
                }else{
                    cout<<'0';
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
