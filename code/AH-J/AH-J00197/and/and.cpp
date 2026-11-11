#include<bits/stdc++.h>
using namespace std;
struct nb{
	int x;int p;
}a[2000002];
bool bmp(nb a1,nb a2){
	return a1.x>a2.x;
}
bool bmp1(nb b1,nb b2){
	return b1.p<b2.p;
}
int wei(int a,int b){
	int a1[1002],b1[1002];
	int cnt1=0,cnt2=0;
	while(a>0){
		cnt1++;
		a1[cnt1]=a%2;
		a/=2;
	}
	while(b>0){
		cnt2++;
		b1[cnt2]=b%2;
		b/=2;
	}
	int c[max(cnt1,cnt2)+2];
	memset(c,0,sizeof(c));
	for(int i=1;i<=max(cnt1,cnt2);i++){
		if(a1[i]==b1[i]==1)
			c[i]=1;
		else c[i]=0;
	}
	long long int sum=1,ccf=0;
	for(int i=1;i<=max(cnt1,cnt2);i++){
		ccf+=sum*c[i];
		sum*=2;
	}
	return ccf;
}
int b[2000002];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].p=i;
	}
	sort(a+1,a+1+n,bmp);
	sort(a+1,a+1+m,bmp1);
	long long int ans=a[1].x;
	for(int i=2;i<=m;i++)
		ans=wei(a[i].x,ans);
	cout<<ans;
	return 0;
}
