#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
long long sum;
string s,s1,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    while(n--){
        scanf("%d%c",&a,&c);
        while(a--)s+=c;
    }
    string ss=s;
    reverse(s.begin(),s.end());
    if(s==ss){
        printf("0");
        return 0;
    }
    sum=ss.size()/2;
    for(int i=0;i<=ss.size()/2-1;i++){
        s1+=ss[i];
    }
    for(int i=ss.size()/2+s.size()%2;i<ss.size();i++){
        s2+=ss[i];
    }
    reverse(s2.begin(),s2.end());
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[i]){
            sum--;
        }
    }
    printf("%lld",sum);
    return 0;
}
