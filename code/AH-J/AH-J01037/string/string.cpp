#include <bits/stdc++.h>
using namespace std;
long long s[200010];
struct node{
    int sum;
    char ch;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].sum>>a[i].ch;
        s[i]=s[i-1]+a[i].sum;
    }
     long long ans=1,sum=0;
     char p=a[ans].ch;
     for(long long i=1;i<=s[n]/2;i++){
		 if(i>s[ans]) p=a[++ans].ch;
	     int pos=lower_bound(s+1,s+n+1,s[n]-i+1)-s;
         char x=a[pos].ch;
         if(x!=p) sum++;
     }  
     cout<<sum;
    return 0;
}
