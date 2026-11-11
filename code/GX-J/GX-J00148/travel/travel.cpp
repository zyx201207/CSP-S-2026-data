#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int cnt=0;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    cout<<"1"<<' ';
    for(int i=0;i<s1.size()-1;i++){
        for(int i=0;i<s2.size()-1;i++){
            if(s1[i]==s2[i]){
                cnt++;
            }
        }
    }
    if(cnt==2){
        cout<<"1"<<' ';
    }else cout<<"0"<<' ';
    return 0;
}
