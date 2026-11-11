#include <bits/stdc++.h>
using namespace std;
int n,a[200100],b[200100];
char s[200100];
long long ans,mid,l,rn,r;
bool f=false,g=false;
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		b[i]=b[i-1]+a[i];
	}
	mid=(b[n]+1)/2;
	rn=n+1;
	if(b[n]%2==1) f=true;
	l=b[1]-b[0];
	for(int i=1;b[i]-l<=mid;i++){
		l=b[i]-b[i-1];
		for(;l>0;){
			if(r==0){
				rn--;
				r=b[rn]-b[rn-1];
			}
			g=false;
			if(s[i]!=s[rn]){
				g=true;
					cout<<rn<<" "<<i<<endl;
			}
			if(l>=r){
					l-=r;
					if(g) ans+=r;
					r=0;
				}
			else{
					r-=l;
					if(g) ans+=l;
					l=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
