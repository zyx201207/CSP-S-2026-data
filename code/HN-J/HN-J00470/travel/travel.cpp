#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    char c=getchar();
    int f=1,x=0;
    while(!isdigit(c)){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    vector<bool> ans(4,0);
    int num1,num2;
    string s1,s2;
    cin>>num1>>s1>>num2>>s2;
    int row1=(s1[0]-'0')*10+s1[1]-'0';
    int row2=(s2[0]-'0')*10+s2[1]-'0';
    char c1=s1[2],c2=s2[2];
	    if(num1==num2){
    
        ans[0]=true;
        if(row1==row2){
            ans[1]=true;
            if((c1>='D'&&c2>='D')||(c1<'D'&&c2<'D')){
                ans[2]=true;
                if(abs(c1-c2)==1){
                    ans[3]=true;
                }
            }
        }
    }
    int num=0;
    for(int i=0;i<4;i++){
        cout<<(int)ans[i];
    }
    return 0;
}

