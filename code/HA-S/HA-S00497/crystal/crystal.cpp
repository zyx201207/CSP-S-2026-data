#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],maxn,flag1=1,flag2=1,cha;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		cha=a[2]-a[1];
		if(a[i]!=i) flag1=0;
		if(i>=2&&a[i]-a[i-1]!=a[2]-a[1]) {
			flag2=0;
		}
	}
	
	if(flag1){
		
	long long num=sqrt(2*m)+10;
	while(num*num+num>2*m) num--;
	cout<<min(n,num+1);
	return 0;
		
	}
//	cout<<cha;
	if(flag2){
		
	long long num=1;
	while(num*num*cha + num*cha<=2*m) num++;
	cout<<min(n,num);
	return 0;
	
	}
//	cout<<endl;
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long num=m,ans=0;
		for(int j=i;j>=1;j--){
			if(num>=a[i]-a[j]){
				num-=a[i]-a[j];
				ans++;
			}else break;
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
