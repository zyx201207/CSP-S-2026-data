#include<bits/stdc++.h>
using namespace std;
long long n,b[200005],r,ans,l=1,ll=1,rr=1,last,lastt;
char a[200005];
char x,y;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	/*cin>>n;
	rr=n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		cin>>a[i];
		r+=b[i];
	}
	x=a[1],y=a[n];
	l=b[1],r=n-b[n];
	int c=l-1+1,d=n-r+1;
	last=min(c,d);
	if(a[ll]!=a[rr]) ans=last;
	lastt=last;
	for(int i=1;i<=n;i++)
	while(l<r){
		int lll,rrr;
		if(n-r>l-1){
			ll++;
			x=a[ll];
			lll=l;
			l+=b[ll];
			int t1=l-1+1,t2=n-r+1;
			int t3=min(t1,t2)-last;
			if(x!=y) ans+=last-lastt;
			last=t3;
			lastt=last;
		}
		else{
			rr--;
			y=a[rr];
			rrr=r;
			r-=b[rr];
			int t1=l-1+1,t2=n-r+1;
			int t3=min(t1,t2)-last;
			if(x!=y) ans+=last-lastt;
			last=t3;
			lastt=last;
		}
	}
	cout<<ans;*/
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		cin>>a[i];
		for(int j=1;j<=b[i];j++) s+=a[i];
	}
	for(int l=0,r=s.size()-1;l<r;l++,r--){
		if(s[l]!=s[r]) ans++;
	}
	cout<<ans;
	return 0;
}
