#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
long long n,m;
cin>>n>>m;
vector<int>s(n+1);
for(int i=0;i<n;i++)
{
    cin>>s[i+1];
}
vector<int>left(m+1,0);
int same=0;
for(int i=1;i<=n;i++){
    int l=i-1;
    vector<int>pre(l+1);
    for(int j=i-1;j<i;j++){
        pre[j]=0;
    }
    for(int j=i;j<=n;j++)
    {
        for(int k=i-1;k<l+1;k++)
        {
            if(pre[k]==s[j])
            {
                for(int h=k;h<l+1;h++)
                {
                    pre[h]=0;
                }
                l=k+1;
                pre[k]=s[j];
                same++;
                k=l+1;
            }
        }
        if(same==0){
            pre[l+1]=s[j];
            l++;
        }
        same=0;
    }
    for(int x=0;x<m;x++)
    {
        for(int j=0;j<l+1;j++){
            if(pre[j]==x+1)
            {
                left[x]++;
                j=l+1;
            }
        }
    }

}
for(int i=0;i<m;i++){
    cout<<left[i]<<' ';
}

return 0;
}
