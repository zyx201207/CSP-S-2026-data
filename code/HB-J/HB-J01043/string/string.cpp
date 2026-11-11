#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a;
    char c;
    string s;
    char s1[200000]={ },s2[200000]={ };
    int x,y=0,sum=1,m=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        x=a;
        while(x!=0){
            s[y]=c;
            x--;
            y++;
        }
        if(y/2==0){
            for(int j=0;j<y/2;j++){
                s1[j]=s[j];
            }
            for(int j=y-1;j>=y/2;j++){
                s2[m]==s[j];
                m++;
            }
            for(int j=0;j<y/2;j++){
                if(s1[j]!=s2[j]) sum++;

            }
        }
        if(y/2==1){
            for(int j=0;j<y/2;j++){
                s1[j]=s[j];
            }
            for(int j=y-1;j>y/2;j++){
                s2[m]=s[j];
                m++;
            }
            for(int j=0;j<y/2;j++){
                if(s1[j]!=s2[j]) sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
