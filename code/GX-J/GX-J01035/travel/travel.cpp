    #include<bits/stdc++.h>
    using namespace std;
    string s[20][20],c[20][20];
    int ans[20];
    char d[20];
    int main()
    {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=2;j++)
        {
            cin>>s[i][j]>>c[i][j];
        }
    }
    for(int i=1;i<=2;i++)
    {
        for(int j=0;j<s.size();j++)
        {

            if(c[i][j]>='0' and c[i][j]<='9'){ans[i]=ans[i]+c[j];ans=ans*10;}
            if(c[i][j]>='A' and c[i][j]<='Z'){d[i]=c[i][j];}
        }
    }
    if(s[1]==s[2]){cout<<"1";}
    else
        cout<<"0";
    if(s[1]==s[2] and ans[1]==ans[2]){cout<<1;}
    else
        cout<<0;
    if(s[1]==s[2] and ans[1]==ans[2] and d[1]==d[2])cout<<1;
    else
        cout<<0;
    if(s[1]==s[2] and ans[1]==ans[2] and d[1]==d[2] and d[1]-d[2]==1)cout<<1;
    else
        cout<<0;
    return 0;
    }
