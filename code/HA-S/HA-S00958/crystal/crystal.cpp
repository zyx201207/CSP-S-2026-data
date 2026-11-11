#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,num,maxn,sun;
long long a[500005];
bool c;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	c=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]!=i+1){
			c=false;
		}
	}
	if(c){
		ans=1;
		num=0;
		for(int i=1;i<n;i++){
			num=num+i;
			if(m>=num){
				ans++;
			}
		}
		printf("%d",ans);
		return 0;
	}
	maxn=0;
	num=1;
	for(int i=1;i<n;i++){
		sun=m-(a[i]-a[i-1])*num;
		if(sun>=0){
			m=sun;
			num++;
		}else{
			maxn=max(num,maxn);
			m=m+(a[i-1]-a[i-num]);
			num--;
			i=i-1;
		}
	}
	maxn=max(num,maxn);
	printf("%d",maxn);
	return 0;
}
