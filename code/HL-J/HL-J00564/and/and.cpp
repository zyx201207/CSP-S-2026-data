#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(int a,int b){
	return a>b;
}
long long m2(int a){
	long long ans=1;
	while(ans<=a){
		ans*=2;
	}
	return ans/2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long mao=0;
	long long num=0;
	long long begin=1;
	for(int i=1;i<=n;i++){
		mao=m2(a[1]);
		if(a[i]>=mao){
			num++;
			if(num>=m){
				ans=a[i];
				for(int j=1;j<=i;j++){
					ans&=a[j];
				}
				cout<<ans;
				return 0;
			}
		}
		else{
			num=1;
			for(int i=1;i<=n;i++){
				if(a[i]>=mao) a[i]-=mao;
			}
			sort(a+1,a+n+1,cmp);
			i=1;
		}
	}
	cout<<0;
	return 0;
}
