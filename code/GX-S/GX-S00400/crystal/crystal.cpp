#include <bits/stdc++.h>
using namespace std;
long long s,f=0,n,m,cnt,ans,maxcnt,c,ccc,aaa=1;
long long  a[100005],b[100005],c1[100005];


//bool soort(int a1,int b1){
//	return a1<b1;};
int main(){
	freopen("crytal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	
	cin>>n>>m;
	if(n==1){cout<<1;return 0;}
	for(int i=0;i<n;i++){
		cin>>a[i];
		c=a[i];
		b[c]+=1;
		c1[i]=a[i]-a[i-1];
		if(c1[i]!=c1[i-1]){aaa=0;}}
	sort(a,a+n);
	if(aaa==1){cout<<m/c1[n/2]+1;return 0;}
	for(int k=1;k<=n;k++){
		cnt=1;
		ans=m;
		ccc=a[k];
		
		for(int t=k;t>=0;t--){
			if(ccc-a[t-1]<=ans){
				ans=ccc-a[t-1];
				cnt++;
				maxcnt=max(cnt,maxcnt);
				}
			else{continue;}
			t--;}
			}
	cout<<maxcnt+1;
	return 0;}
