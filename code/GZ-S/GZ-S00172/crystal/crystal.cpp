//GZ-S00172 中央民族大学附属中学贵阳学校 杨忠瀚 
#include<bits/stdc++.h>
using namespace std;
long long s[500005],n,a[500005],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0)s[i]=s[i-1]-a[i];
		else s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	long long cnt=1;
	for(int i=2;i<=n;i++){
		if(!(m-s[cnt]))break;
		if(s[i]-a[i]<=m){
			cnt=i;
		}
	}
	if(cnt==1)cnt=0;
	cout<<cnt;
	return 0;
}
