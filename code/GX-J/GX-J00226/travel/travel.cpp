#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string r1,r2,x1,x2;
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1)cout<<1;
    else cout<<0;
    if(r1==x1&&r2[0]==x2[0]&&r2[1]==x2[1])cout<<1;
    else cout<<0;
    if(r1==x1&&r2[0]==x2[0]&&r2[1]==x2[1]){
       if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C')
          if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C')cout<<1;
          else cout<<0;
       else if(x2[2]=='D'||x2[2]=='F')cout<<1;
       else cout<<0;
    }else cout<<0;
    map<char,int>t;
    t['A']=1,t['B']=2,t['C']=3,t['D']=5,t['F']=6;
    if(r1==x1&&r2[0]==x2[0]&&r2[1]==x2[1]&&abs(t[r2[2]]-t[x2[2]])==1)cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
