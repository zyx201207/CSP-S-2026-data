#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char s1,s2;
    cin>>a>>c>>s1>>b>>d>>s2;
    if(a==b)cout<<1;
    else {
		cout<<"0000";
		return 0;
		}
    int f=0;
    if(c==d){
        cout<<1;
        if((s1=='A' or s1=='B' or s1=='C') and (s2=='A' or s2=='B' or s2=='C'))cout<<1;
        else if((s1=='D' or s1=='F') and (s2=='D' or s2=='F'))cout<<1;
        else cout<<0;
        f=1;
    }
    else cout<<0<<0;
    if((s1-s2==1 or s2-s1==1) and s1!='C' and s1!='D' and s2!='C' and s2!='D' and f)cout<<1;
    else cout<<0;
    
    return 0;
}
