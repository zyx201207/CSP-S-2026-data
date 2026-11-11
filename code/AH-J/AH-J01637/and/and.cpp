#include<bits/stdc++.h>
using namespace std;
/*
4 2
3 15 12 12 
 */
int n,m;
long long a[200005],maxn=-1,max2=-1;
long long change(int x){//10->2
	int ans=0,i=0;
	while(x!=0){
		ans*=10;
		ans+=x%2;
		x/=2;
	} 
	return ans;
}
long long f(int x,int y){//&
	long long ans=0,i=0;
	while(x!=0&&y!=0){
		if(x%10==y%10&&x%10==1){
			ans+=pow(10,i);
		}
		x/=10,y/=10;
	}
	return ans;
}
long long cha(int x){//2->10
	int i=0;
	long long ans=0;
	while(x!=0){
		ans+=x%10*pow(2,i);
		x/=10;
		i++;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(maxn<=a[i]){
			swap(maxn,max2);
			maxn=a[i];
		}
		else if(max2<=a[i]) max2=a[i];
	}
	if(m==1) {
		cout<<maxn;
		return 0;
	}
	if(m==2){
		int x=change(maxn),y=change(max2);
		cout<<cha(f(x,y));
	}
	return 0;
}
