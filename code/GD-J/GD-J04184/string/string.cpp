#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long l[N],r[N],len[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len[i]>>c[i];
		l[i]=r[i-1]+1;
		r[i]=l[i]+len[i]-1;
	}
	long long ans=0;
	int ll=1,rr=n;
	while(ll<=rr){
		int lenn=min(len[ll],len[rr]);
		if(c[ll]!=c[rr])ans+=lenn;
		if(len[ll]<len[rr]){
			ll++;r[rr]-=lenn;len[rr]=r[rr]-l[rr]+1;
		}
		else if(len[ll]>len[rr]){
			rr--;l[ll]+=lenn;len[ll]=r[ll]-l[ll]+1;
		}
		else ll++,rr--;
	}
	cout<<ans;
	return 0;
}/*
3 
2 a
2 b
1 c

*/
