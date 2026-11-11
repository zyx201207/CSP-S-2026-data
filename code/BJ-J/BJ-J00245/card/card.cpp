#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
long long n,m;
long long a[500005],f[300005],f2[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
        for(int i=1;i<=n;i++){
        cin>>a[i];f[i]=0;}
    stack<int> s;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(f[a[j]]>0)
                    while(s.top()!=a[j])
                    s.pop();
                else{s.push(a[j]);f[a[j]]++;}
            }
            while(!s.empty()){
            f2[s.top()]++;
            s.pop();
            }
            for(int i=1;i<=n;i++)
            f[i]=0;
        }
        for(int i=1;i<=m;i++){
        cout<<f2[i];
        if(i!=n)
        cout<<' ';
        }cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}