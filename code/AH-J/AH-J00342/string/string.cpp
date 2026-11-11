#include<bits/stdc++.h>
using namespace std;
long long n;
char c;
string s;
bool flag=0;
struct stu{
    char a;
    long long p;
}a[200005];
long long f(string x){
    long long cnt=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].p>>a[i].a;
        if(i==1){
            c=a[1].a;
        }
        if(c!=a[i].a){
            flag=1;
        }
    }
    if(flag==0){
        cout<<0;
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i].p;j++){
                s+=a[j].a;
            }
        }
        cout<<f(s);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

