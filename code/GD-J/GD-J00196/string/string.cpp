#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int n;
int a[200005],s[200005];
char c[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	ll sum=0,tot=0;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i],tot+=a[i],s[i]=tot;
	char chl,chr;
	ll l=a[1],r=a[n],curl=1,curr=n;
	ll mid=(tot+1)/2;
	ll ans=0;
	while(curl<curr){
//		cout<<l<<' '<<r<<' '<<curl<<' '<<curr<<' '<<ans<<endl;
		if(l<r){
			if(c[curl]!=c[curr]){
				ans+=l;
			}
			r-=l;
			l=a[curl+1];
			curl++; 
		}
		else if(l==r){
			if(c[curl]!=c[curr])
				ans+=l;
			curl++;
			curr--;
			r=a[curr],l=a[curl]; 
		}
		else{
			if(c[curl]!=c[curr])
				ans+=r;
			l-=r;
			r=a[curr-1];
			curr--; 
		}
	}
	cout<<ans<<endl;
	return 0;
} 
/*
6
3 a
2 b
1 a
2 b
1 c
2 a
*/
