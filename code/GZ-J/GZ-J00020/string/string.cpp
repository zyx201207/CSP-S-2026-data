//姓名：李承峰 学校：观山湖区外国语实验中学 准考证号：GZ-J00020
#include<bits/stdc++.h>
using namespace std;

string s,s1,s2;
long long cnt=0;
int n;

string v(string a){
    string b={};
    long long len1 = a.size();
    for(long long i=len1-1;i>=0;i--){
        b+=a[i];
    }
    return b;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long a;
        char x;
        cin>>a>>x;
        s+=a*x;
    }
    long long len = s.size();
    for(long long i=0;i<=(len+1)/2;i++){
        s1[i]=s[i];

    }
    for(long long i=len/2+1;i<len;i++){
        s2+=s[i];
    }

    s2=v(s2);
    for(long long i=0;i<=(len+1)/2;i++){
        if(s1[i]!=s2[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
