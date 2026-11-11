#include<bits/stdc++.h>
using namespace std;
long long n,cnt,zhi;
struct s{
    long long num,z;
    char zi;
};
struct s s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].num>>s[i].zi;
    }
    bool flag=0;
    s[0].zi=s[1].zi;
    for(int i=1;i<=n;i++){
        s[i].z=0;
        if(s[i].zi!=s[1].zi){
            flag=1;
            break;
        }
    }
    if(!flag){
        for(int i=1;i<=n;i++){
            cout<<s[i].num<<' '<<s[i].zi<<endl;
        }
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n/2;i++){
        int j=n+1-i;
        if(s[i].zi!=s[j].zi||s[i].num!=s[j].num){
            if(s[i].num<=s[j].num){
                s[j].zi=s[i].zi;
                s[j-1].z+=s[j].num-s[i].num+s[i].z+s[j].z;
                zhi=s[j-1].z;
                //cnt+=s[j].num-s[i].num;
                s[j].num=s[i].num;
                cnt+=s[j].num;
            }
            else if(s[i].num>s[j].num){
                s[i].zi=s[j].zi;
                s[i+1].z+=s[i].num-s[j].num+s[i].z+s[j].z;
                zhi=s[i+1].z;
                //cnt+=s[i].num-s[j].num;
                s[i].num=s[j].num;
                cnt+=s[i].num;
            }
        }
    }
    cnt+=zhi;
    cout<<zhi;
    for(int i=1;i<=n;i++){
        cout<<s[i].num<<' '<<s[i].zi<<endl;
    }
    cout<<cnt;
    return 0;
}

