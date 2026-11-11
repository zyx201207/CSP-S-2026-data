//GZ-S00289 贵阳市第三实验中学 陈典伸 
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005];
long long ans=1;
long long cha(int I){
	long long  zong=0,i=I,anss=0;
	while((m-zong)>(a[I]-a[i])&&i>=0){
		zong+=(a[I]-a[i]);
		anss++;
		i--;
	}
	return anss;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+0,a+n);
	for(int i=n-1;i>=0;i--){
		if(a[i]==a[i-1]){i--;}
		else {
			int B=cha(i);
			if(B>ans){
				ans=B;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<ans;
	}
	return 0;
}
