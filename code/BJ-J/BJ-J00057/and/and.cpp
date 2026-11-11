#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],pd[5000005],p,t[300005],ans;
string s[500005],trash1,trash2;
string bin(int str){
    trash1=trash2='\0';
    while(str!=0){
        trash1.append(to_string(str%2));
        str/=2;
    }
    for(int i=trash1.length()-1;i>=0;i--){
        trash2.push_back(trash1[i]);
    }
    return trash2;
}
int yu(string s1,string s2){
    int k=1,sum=0;
    for(int i=max(s1.length(),s2.length())-3;i>=0;i--){
        if(s1[i]==s2[i]){
            sum+=k;
        }
        k*=2;
    }
    return sum;
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        s[i]=bin(a[i]);
    }
    for(int i=1;i<m;i++){
        ans+=yu(s[i],s[i+1]);
    }
    cout<<ans;
    return 0;
}
