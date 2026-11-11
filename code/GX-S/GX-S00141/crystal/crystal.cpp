#include<bits/stdc++.h>
using namespace std;
long long n,m,goal,zs;
long long number;
int sy;
string s,num;
long long be(long long goal,int sy,string num){
    if(sy!=0)
   {
        for(int y=0;y<num.size();y++){
            for(int x=1;x<=sy;x++){
                if(((num[y]-48)+x)==goal){
                    number+=1;
                    sy-=x;
                    num=num.substr(y-1,num.size());
                    break;
              }
            }
        }
       be(goal,sy,num);
   }
   else{
        return number;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int e=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int max1=0;
    for(int i=0;i<n;i++){
        int b=s[i]-48;
        if(b>max1)
       {
            max1=b;
        }
    }
    int max2=0;
    for(int i=0;i<s.size();i++){
        goal=s[i];
        if((s[i]-48)==max1){
            continue;
        }
        else{
            e=be(goal,m,s);
        }
        if(e>max2)
        {
            max2=e;
        }
    }
    cout<<e;
}
