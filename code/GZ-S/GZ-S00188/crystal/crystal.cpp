/*GZ-S00188 贵阳市第二实验中学 莫卓均*/ 
#include<bits/stdc++.h>
using namespace std;
long long m,a[1000001],s[100001][100001];
int ans=INT_MIN,n;
void aaa(int d,long long b,int c,int x){//a cs  b e  c i  x zi
	if(b==0){
		ans=max(ans,d);
		return ;
	}
	else if(b<0){
		ans=max(ans,d-1);
		return ;
	}
	for(int i=c-1;i>=1;i--){
		b-=s[x][i];
		aaa(d+1,b,i,x);
		b+=s[x][i];
	}
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			s[i][j]=a[i]-a[j];
		}
	}
	for(int i=1;i<=n;i++){
		aaa(1,m,i,i);
	}
	cout<<ans;
	return 0;
}
