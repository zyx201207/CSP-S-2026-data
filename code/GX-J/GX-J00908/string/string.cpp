#include<bits/stdc++.h>
using namespace std;
long long n,ans,len;
vector<long long>a;vector<char>c;
void mid(){
	long long i,t;
	for(i=0;i<n;i++){
		t+=a[i];
		if(t*2==len)return;
		if(t*2>len)break;
	}
	n++;
	a[i]=len/2-(t-a[i]);
	a.insert(a.begin()+i+1,t-len/2);
	c.insert(c.begin()+i+1,c[i]);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		long long t;char tc;
		cin>>t>>tc;
		a.push_back(t);c.push_back(tc);
		len+=t;
	}
	mid();
	long long l=0,r=n-1,tl=a[0],tr=a[n-1],last=0;
	while(tl+tr<=len){
		if(c[l]!=c[r])ans+=min(tl,tr)-last;
		last=min(tl,tr);
		if(tl<=tr)tl+=a[++l];
		else tr+=a[--r];
	}
	cout<<ans<<endl;
	return 0;
}
