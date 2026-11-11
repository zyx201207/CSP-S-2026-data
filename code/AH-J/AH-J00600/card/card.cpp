#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005],b[300005],c[300005];
//a 牌的顺序 b 牌种类数组
string s=" ";
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int p=1;p<=m;p++){
            b[p]=0;
        }
        s=" ";
        for(int j=i;j<=n;j++){
            if(b[a[j]]==0){//a[j]为牌
                s+=a[j]+'0';
                b[a[j]]++;
            }
            else{
                int t=0;
                string s1=" ";
                for(int w=1;w<s.size();w++){
                    if(s[w]==a[j]+'0')
                    {
                        t=w;
                        s1+=s[w];
                        break;
                    }
                    else{
                            s1+=s[w];
                    }
                }
                for(int q=t+1;q<s.size();q++)
                    b[s[q]-'0']=0;
                s=s1;
            }
            if(j==n){
                for(int k=1;k<=m;k++){
                    c[k]+=b[k];
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
