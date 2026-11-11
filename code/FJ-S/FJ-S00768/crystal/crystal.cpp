#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//1 2 5 6 9
	//1 1 3 1 3
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	bool flag=false;
	sort(a+1,a+n+1);
	long long ma=INT_MIN;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			long long ans=0;
			for(int k=1;k<=n;k++){
				if(a[k]==a[1])ans++;
			}
			ma=max(ma,ans);
			while(m>0&&a[j]<a[i]){
				a[j]++;
				m--;
			}
		}
	}
	cout<<ma;
	return 0;
} 
