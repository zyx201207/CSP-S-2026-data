#include<bits/stdc++.h>
using namespace std;
int main(){

freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;
long long a[20010];
string s[20010];
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+1+n);

for(int i=1;i<=n;i++){
    while(a[i]>=1){
        char k=a[i]%2+'0';
        a[i]/=2;
        s[i]+=k;
    }

}
int t=0,ma=0;
string s1=s[n],s2=s[n-1];
for(int i=n;i>n-m+1;i--){

    for(int x=s1.size()-1;x>=0;x--){

        if(s1[x]==s2[x]) t=t*10+1;
        else t*=10;
    }
    s1=t;
    s2=s[i-1];
}
t/10;
int sum=1;
if(t%10!=0) ma+=1;
t/10;
while(t){
    if(t%10==0){
        t/10;
        sum++;
        continue;
    }else{
        sum++;
        int c=1;
        for(int i=1;i<=sum;i++){
            c*=2;
        }
        ma+=c;
        t/10;
    }
}
cout<<ma;

return 0;
}
