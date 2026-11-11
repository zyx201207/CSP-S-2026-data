#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
long long a[200005];
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    if(m==1){
        s1='1';
    }
    else if(m==2){
        s1="10";
    }
    else{
            while(m>2){
            if(m%2==1){
                s2+='1';
            }
            else{
                s2+='0';
            }
            m/=2;
            }
        for(int i=0;i<s2.size();i++){
            s1[i]=s2[s2.size()-i+1];
        }
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];

        while(a[i]/2!=0||a[i]/2!=1){
            if(a[i]%2==1){
                s+='1';
            }
            else{
                s+='0';
            }
        }
        int sum=0;
        for(int j=0;j<max(s.size(),s1.size());j++){
            if(s[j]=='1'&&s1[j]=='1'){
                sum++;
            }
        }
        maxn=max(maxn,sum);
    }
    cout << maxn;
    return 0;
}
