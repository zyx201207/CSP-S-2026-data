#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt,sum;
string s[200005],ans;
void Save(int t,int i){
    while(t){
        s[i]=char(t%2+'0')+s[i];
        t/=2;
    }
    //cout<<s[i]<<endl;
    cnt=max(cnt,int(s[i].size()));
    if(int(s[i].size())<cnt){
        int x=s[i].size();
        for(int j=cnt;j>x;j--)s[i]='0'+s[i];
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        Save(a[i],i);
    }
    for(int i=0;i<cnt;i++)ans=ans+'1';
    for(int i=n;i>=n-m+1;i--){
        for(int j=0;j<cnt;j++){
            ans[j]=min(ans[j],s[i][j]);
        }
    }
    int c=1;
    for(int i=cnt-1;i>=0;i--){
        sum+=c*(ans[i]-'0');
        c*=2;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
