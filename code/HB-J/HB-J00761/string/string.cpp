#include<bits/stdc++.h>
using namespace std;
long long n,mid,midd,middd,m=0,t=1,l1,l2,ans,t1=1,t2=1;
struct node{long long x;char y;}a[200005];
node a1[200005],a2[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;for(int i=1;i<=n;i++){cin>>a[i].x>>a[i].y;m+=a[i].x;}
	if(m%2==1){mid=m/2+1;}
	else{mid=m/2;middd++;}
	int t=0;
	for(int i=1;i<=n;i++){
		t+=a[i].x;
		if(t>=mid){midd=i;middd+=mid-t+a[i].x-1;break;}
	}
	//cout<<mid<<" "<<midd<<" "<<middd;
	l1=midd;l2=n-midd;
	for(int i=1;i<midd;i++){a1[i].x=a[i].x;a1[i].y=a[i].y;}
	a1[midd].y=a[midd].y;a1[midd].x=middd;
	for(int i=n;i>midd;i--){a2[n-i+1].x=a[i].x;a2[n-i+1].y=a[i].y;}
	if(middd+1!=a[midd].x && m%2==1){l2++;a2[n-midd+1].y=a[midd].y;a2[n-midd+1].x=a[midd].x-middd-t;}
	if(middd!=a[midd].x&&m%2==0){l2++;a2[n-midd+1].y=a[midd].y;a2[n-midd+1].x=a[midd].x-middd;}
	//cout<<endl;
	while(a1[t1].x!=0||a2[t2].x!=0){
		if(a1[t1].y==a2[t2].y&&a1[t1].x>a2[t2].x) {a1[t1].x-=a2[t2].x;t2++;}
		else if(a1[t1].y==a2[t2].y&&a1[t1].x<a2[t2].x) {a2[t2].x-=a1[t1].x;t1++;}
		else if(a1[t1].y==a2[t2].y&&a1[t1].x==a2[t2].x) {t2++;t1++;}
		else if(a1[t1].y!=a2[t2].y&&a1[t1].x>a2[t2].x) {a1[t1].x-=a2[t2].x;ans+=a2[t2].x;t2++;}
		else if(a1[t1].y!=a2[t2].y&&a1[t1].x<a2[t2].x) {a2[t2].x-=a1[t1].x;ans+=a1[t1].x;t1++;}
		else if(a1[t1].y!=a2[t2].y&&a1[t1].x==a2[t2].x) {ans+=a2[t2].x;t2++;t1++;}
		//cout<<ans<<" ";
	}
	cout<<ans;
	return 0;
}

