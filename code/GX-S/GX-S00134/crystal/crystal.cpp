#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000],b[600000],ans=1,x[600000];
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int k=a[2]-a[1],flag=0;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=k) flag=1;
		b[a[i]]++;
	}
	sort(a+1,a+1+n);
	if(flag){
	for(int i=1;i<=n;i++){
		long long num=m,cnt=b[a[i]],l1=i-1;
		while(num!=0&&l1>0){
			long long x=a[i]-a[l1];
			if(x==0){
				l1--;
				continue;
			}
			if(num>=x){
				num-=x;
				l1--;
				cnt++;
			}
			else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
	else{
		x[1]=k;
		int i;
		for(i=2;i<=n;i++){
			x[i]=x[i-1]+k;
			if(x[i]>m) {
				i--;
				break;
			}
		}
	cout<<i+1;
}
return 0;
}
