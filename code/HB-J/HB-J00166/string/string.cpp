#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char s[200003],b[200002];
    int n,a[200002],c=1,sum=0,num=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=c;j<=c+a[i];j++){
            s[j]=b[i];
        }
        c+=a[i];
    }
    int head=1,tail=sum;
    if(sum%2==0){
        while(!(head<tail)){
            if(s[head]!=s[tail])num++;
            head++;
            tail--;
        }
        cout<<num;
    }
    else
    {
        while(!(head==tail)){
            if(s[head]!=s[tail])num++;
            head++;
            tail--;
        }
        cout<<num;
    }
    return 0;
}
