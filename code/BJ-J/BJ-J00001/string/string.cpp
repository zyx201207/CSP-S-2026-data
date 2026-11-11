#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,li=0,ri=0,lc=0,rc=0,len=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		len+=a[i];
	}
	ri=n-1;
	rc=a[n-1]-1;
	while(li<ri||(li==ri&&lc<rc)){
		long long mn=min(a[li]-lc,rc+1);
		if(s[li]!=s[ri])ans+=mn;
		lc+=mn;
		rc-=mn;
		if(lc==a[li]){
			li++;
			lc=0;
		}
		if(rc==-1){
			ri--;
			rc=a[ri]-1;
		}
	}
	cout<<ans;
	return 0;
}