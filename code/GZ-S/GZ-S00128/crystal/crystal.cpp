//GZ-S00128 贵阳市第一中学 赵志杰
#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
const long long LL=1e18;
int n,maxn,minn,ans1,ans2,ans,l;
long long num,m;
int a[MAXN];
priority_queue<long long> s;
bool t=1;
int pd(int x,int y){
	return max(x,y)-min(x,y);
}
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=i)t=0;
	}
	if(m==0){
		ans1=1;
		for(int i=1;i<n;i++){
			if(a[i]==a[i-1])ans1++;
			else{
				ans=max(ans,ans1);
				ans1=1;
			}
		}
		printf("%d",&ans);
		return 0;
	}
	if(t==1){
		ans=1;
		int su=1;
		while(1){
			if(num+su<=m){
				ans++;
				num+=su;
				su++;
			}
			else{
				break;
			}
		}
		printf("%d",&ans);
		return 0;
	}
	t=1;
	for(int i=2;i<n;i++){
		if(a[i-1]-a[i-2]!=a[i]-a[i-1]){
			t=0;
			break;
		}
	}
	if(t){
		ans=1;
		int su=a[1]-a[0];
		while(1){
			if(num+su<=m){
				ans++;
				num+=su;
				su+=a[1]-a[0];
			}
			else break;
		}
		printf("%d",ans);
		return 0;
	}
	sort(a,a+n,cmp);
	maxn=a[n-1];
	minn=a[0];
	l=(minn+maxn)/2;
	for(int j=0;j<n;j++){
		if(a[j]>l)break;
		s.push(LL-pd(a[j],l));
	}
	for(int j=0;j<n;j++){
		if(a[j]>l)break;
		if(num+(LL-s.top())<=m){
			num+=LL-s.top();
			ans++;
		}
		s.pop();
	}
	while(minn!=maxn){
		l=(minn+maxn)/2;
		int l1=(l+minn)/2;
		for(int j=0;j<n;j++){
			if(a[j]>l1)break;
			s.push(LL-pd(a[j],l1));
		}
		for(int j=0;j<n;j++){
			if(a[j]>l1)break;
			if(num+(LL-s.top())<=m){
				num+=LL-s.top();
				ans1++;
			}
			s.pop();
		}
		num=0;
		int l2=(l+maxn)/2;
		for(int j=0;j<n;j++){
			if(a[j]>l2)break;
			s.push(LL-pd(a[j],l2));
		}
		for(int j=0;j<n;j++){
			if(a[j]>l2)break;
			if(num+(LL-s.top())<=m){
				num+=LL-s.top();
				ans2++;
			}
			s.pop();
		}
		if(ans1>ans2){
			maxn=l-1;
			l=l1;
		}
		else{
			minn=l+1;
			l=l2;
		}
		ans=max(ans,max(ans1,ans2));
		ans1=0;
		ans2=0;
	}
	l=minn;
	for(int j=0;j<n;j++){
		if(a[j]>l)break;
		s.push(LL-pd(a[j],l));
	}
	for(int j=0;j<n;j++){
		if(a[j]>l)break;
		if(num+(LL-s.top())<=m){
			num+=LL-s.top();
			ans1++;
		}
		s.pop();
	}
	ans=max(ans,ans1);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
