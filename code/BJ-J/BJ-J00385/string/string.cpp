#include<bits/stdc++.h>
using namespace std;
struct nod{
    long long siz;
    char c;
}s[200010];
long long n,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>s[i].siz>>s[i].c;
    }
    int fir=1,las=n;
    while(fir<las)
    {
        if(s[fir].c==s[las].c)
        {
            if(s[fir].siz==s[las].siz)
            {
                fir++;
                las--;
            }
            else if(s[fir].siz<s[las].siz)
            {
                s[las].siz-=s[fir].siz;
                fir++;
            }
            else if(s[fir].siz>s[las].siz)
            {
                s[fir].siz-=s[las].siz;
                las--;
            }
        }
        else{
            ans+=min(s[fir].siz,s[las].siz);
            if(s[fir].siz==s[las].siz)
            {
                fir++;
                las--;
            }
            else if(s[fir].siz<s[las].siz)
            {
                s[las].siz-=s[fir].siz;
                fir++;
            }
            else if(s[fir].siz>s[las].siz)
            {
                s[fir].siz-=s[las].siz;
                las--;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
