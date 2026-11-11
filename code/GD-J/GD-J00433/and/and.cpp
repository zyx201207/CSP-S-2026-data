#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int a[200005];
bool oc[31];
int ans,pred;
bool cmp(int a,int b){
	return a>b;
}
int check(int a){
	if(a==0)return 0;
	int t=1,cnt=0;
	while(a>=t){
		t*=2;
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(n>m){
		sort(a+1,a+n+1,cmp);
		pred=check(a[1]);
		int maxd=0x7fffffff;
		for(int i=1;i<=m;i++)maxd=min(maxd,check(a[i]));
		int last=1;
		while(check(a[last])==maxd and last<=n)last++;
		n=last-1;
		if(n<=m)break;
		if(pred==maxd){
			oc[maxd-1]=1;
			for(int i=1;i<=n;i++)a[i]%=(int)pow(2,maxd-1);
		}
		else{
			for(int i=1;i<=n;i++)a[i]%=(int)pow(2,maxd);
		}
	}
	ans=a[1];
	for(int i=1;i<=m;i++)ans&=a[i];
	for(int i=0;i<=30;i++)if(oc[i])ans+=(int)pow(2,i);
	cout<<ans;
	return 0; 
} 
