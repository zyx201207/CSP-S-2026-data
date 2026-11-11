#include<bits/stdc++.h>
using namespace std;
long long sum,ans;
char b[200005];
int a[200005];
long long qz[200005];
/*struct Node1{
    long long s;
    char ch;
}c[200005];
struct Node2{
    long long ss1;
    char c1;
}s1[200005];
struct Node3{
    long long ss2;
    char c2;
}s2[200005];*/
long long n,t,maxn;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    cin>>n;
    cin>>a[1]>>b[1];
    //c[1].s=a[1];
    //c[1].ch=b[1];
    t=1;
    for(int i=2;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        sum+=a[i];
        if(b[i]!=b[i-1]){
            //c[t].s+=a[i];
            t++;}
        //}else{
            //t++;
            //c[t].s=a[i];
            //c[t].ch=b[i];
        //}
    }
    if(n==1||t==1){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s+=b[i];
        }
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])ans++;
    }
    /*qz[1]=c[1].s;
    for(int i=2;i<=t;i++)
    {
        qz[i]=qz[i-1]+c[i].s;
    }
    long long t1;
    for(int i=1;i<=t;i++)
    {
        if(qz[i]>=sum/2){
            t1=i;
            for(int j=1;j<i;j++)
            {
                s1[j].ss1=c[j].s;
                s1[j].c1=c[j].ch;
            }
            s1[i].ss1=sum;
            s1[i].c1=c[i].ch;
            for(int j=t;j>=i+sum%2;j--)
            {
                s2[t-j+1].ss2=c[j].s;
                s2[t-j+1].c2=c[j].ch;
            }
        }
        break;
    }
    int x1=1;
    int x2=1;
    for(int i=1;i<=max(t1,n-t1+sum%2);i++)
    {
        if(s1[x1].c1!=s2[x2].c2){
            if(s1[x1].ss1>s2[x2].ss2){
                ans+=s1[x1].ss1-s2[x2].ss2;
                s1[x1].ss1=s1[x1].ss1-s2[x2].ss2;
                x2++;
            }
            else if(s1[x1].ss1<s2[x2].ss2){
                ans+=s2[x1].ss2-s1[x2].ss1;
                s2[x2].ss2=s2[x2].ss2-s1[x1].ss1;
                x1++;
            }else{
                ans+=s1[x1].ss1;
                x1++;
                x2++;
            }
        }
        else {
            if(s1[x1].ss1<s2[x2].ss2){
                s2[x2].ss2=s2[x2].ss2-s1[x1].ss1;
                x1++;
            }
            else if(s1[x1].ss1>s2[x2].ss2){
                s1[x1].ss1=s1[x1].ss1-s2[x2].ss2;
                x2++;
            }
            else {
                x1++;
                x2++;
            }
        }
    }*/
    cout<<ans;
    return 0;
}
