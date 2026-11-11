#include<bits/stdc++.h>
using namespace std;
long long n,c[200005],a[200005],flag=0,flag1=0;;
long long ans;
string b[200005];
string s,s1;
int hw(string s,int cnt){
    for(int i=0,cnt1=s.size()-1;i<cnt1;i++){
        if(s[i]!=s[cnt1]){
            cnt++;
        }
        cnt1--;
    }
    return cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        c[i]=(b[i][0]-'a');
        s=s+b[i];
        for(int j=1;j<=a[i];j++){
            s1=s1+b[i];
        }
        if(i>1){
            if(a[i]!=a[i-1]){
                flag=1;
            }
            if(c[i]!=c[i-1]){
                flag1=1;
            }
        }
    }
    if(flag1==0){
        cout<<0;
        return 0;
    }
    if(flag==0){
        int x=a[1];
        cout<<x*hw(s,0);
    }else{
        for(int i=0,cnt1=s1.size()-1;i<cnt1;i++,cnt1--){
            if(s1[i]!=s1[cnt1]){
                ans++;
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

