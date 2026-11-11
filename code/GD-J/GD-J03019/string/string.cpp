#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],l,r;
string c[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    long long ans=0;
    l=1,r=n;
    int x=a[1],y=a[n];
    while(l<r){
    	if(c[l]!=c[r]){
		  if(x<y) ans+=x,y-=x,x=a[++l];
		  else if(y<x) ans+=y,x-=y,y=a[--r];
		  else ans+=x,x=a[++l],y=a[--r];
		}
		else{
		  if(x<y) y-=x,x=a[++l];
		  else if(y<x) x-=y,y=a[--r];
		  else x=a[++l],y=a[--r];
		}
	}
	cout<<ans<<'\n';
	return 0;
}
