#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans,d;
bool f=false;
bool cmp(int a,int b){
	return a>b;
}
int solve1(){
	int max_=INT_MIN;
	sort(a+1,a+n+1,cmp);
	for(int k=1;k<=n;k++){
		int tmp=a[k],cnt=0,cnt2=0;
		for(int i=k;i<=n;i++){
			cnt+=tmp-a[i];
			if(cnt>m) break;
			cnt2++;
		}
		max_=max(max_,cnt2);
	}
	return max_;
}
int solve2(){
	 int max_=INT_MIN;
	sort(a+1,a+n+1,cmp);
	for(int k=(1+n)/2-1;k<=n;k++){
		int tmp=a[k],cnt=0,cnt2=0;
		for(int i=k;i<=n;i++){
			cnt+=tmp-a[i];
			if(cnt>m) break;
			cnt2++;
		}
		if(max_>cnt2){
			break;
		}
		max_=max(max_,cnt2);
	}
	return max_;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i>2){
			if(a[i]-a[i-1]!=d){
				f=true;
			}
		}
		if(i>1){
			d=a[i]-a[i-1];
		}
	}
	if(f){
		ans=solve1();
	}
	else{
		ans=solve2();
	}
	printf("%d",ans);
	return 0;
}
