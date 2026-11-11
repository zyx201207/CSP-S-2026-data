#include<bits/stdc++.h>
using namespace std;
struct o{
	long long m;
	char c;
};
long long n,t;
o a[200005];
long long w(){
	long long ans=0;
	long long l=1,r=t,lm=a[1].m,rm=a[t].m;
	long long nw=0,nwi=0;
	while(nwi*2<n){
		if(lm==nw){
			l+=1;
			lm=a[l].m;
		}else{
			lm-=nw;
		}
		if(rm==nw){
			r-=1;
			rm=a[r].m;
		}else{
			rm-=nw;
		}
		nw=min(lm,rm);
		nwi+=nw;
		if(a[l].c!=a[r].c)ans+=nw;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i].m>>a[i].c;
		n+=a[i].m;
	}
	cout<<w();
	
	
	
	return 0;
}
