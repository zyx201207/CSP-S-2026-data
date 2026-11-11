#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo i,j,k,n,m,mm,s,ss,b[400005],pl[400005],pr[400005],ll,rr;
char c[400005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	s=1;
	for(i=1;i<=n;i++){
		cin>>b[i]>>c[i];
		pl[i]=s,pr[i]=s+b[i]-1,s=pr[i]+1;
	}
	ll=1,rr=n;
	for(i=1,j=s-1;i<j;){
		if(pr[ll]-i+1<=j-pl[rr]+1){
			if(c[ll]!=c[rr])ss=ss+(pr[ll]-i+1);
			j-=(pr[ll]-i+1),i=pr[ll]+1,ll++;
		}
		else{
			if(c[ll]!=c[rr])ss=ss+(j-pl[rr]+1);
			i+=(j-pl[rr]+1),j=pl[rr]-1,rr--;
		}
	}
	cout<<ss;
	return 0;
}

