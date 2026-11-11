#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        scanf("%d%c%c",&a,&c,&c);
        for(int j=0;j<a;j++) s+=c;
    }
    string j=s,ss=s;
    reverse(j.begin(),j.end());
    if(s==j) {
        cout<<0;
        return 0;
    }
    int cnt=0,ma=0,i=0;
    while(j!=s){
        s[i]=s[int(s.size())+i-1];
        j=s;
        reverse(j.begin(),j.end());
        cnt++;
    }
    j=s=ss,i=int(s.size()-1);
    reverse(j.begin(),j.end());
    while(j!=s){
        s[i]=s[int(s.size())-i-1];
        j=s;
        reverse(j.begin(),j.end());
        ma++;
    }
    cout<<min(ma,cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}