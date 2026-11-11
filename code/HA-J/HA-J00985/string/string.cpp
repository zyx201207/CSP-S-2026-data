#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005];
long long ans,l,r,lnum,rnum,x[200005],y[200005],maxx;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx+=a[i];
		string s;
		cin>>s;
		b[i]=s[0]-'a'+1;
	}
	r=maxx;
	l=1;
	lnum=1;
	rnum=n;
	for(int i=1;i<=n;i++){
		x[i]=x[i-1]+a[i];
	}
	while(l<r&&lnum<rnum){
		if(b[lnum]!=b[rnum]){
			if(min(x[lnum]-l+1,r-x[rnum-1])==x[lnum]-l+1){
				ans+=x[lnum]-l+1;
				l=x[lnum]+1;
				r=maxx-l+1;
				lnum++;
			}else{
				ans+=r-x[rnum-1];
				r=x[rnum-1];
				l=maxx-r+1;
				rnum--;
			}
		}else{
			if(min(x[lnum]-l+1,r-x[rnum-1])==x[lnum]-l+1){
				l=x[lnum]+1;
				r=maxx-l+1;
				lnum++;
			}else{
				r=x[rnum-1];
				l=maxx-r+1;
				rnum--;
			}
		}
	}
	cout<<ans;
	return 0;
}
