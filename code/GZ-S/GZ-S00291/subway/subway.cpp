//GZ-S00291 张瑞晨 清华中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],c[500010],cnt,pos,maxs=-1,mins=1000000010;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
		if(c[i]<mins&&c[i]!=0){
			mins=c[i];
			pos=i;
		}
	}
	while(m){
		a[pos]+=c[pos];
		if(pos!=1)c[pos-1]+c[pos];
		c[pos]=0;
		mins=1000000010;
		for(int j=1;j<n;j++){
			if(c[j]<mins&&c[j]){
				mins=c[j];
				pos=j;
			}
		}
		m--;
	}
	for(int i=1;i<n;i++){
		if(!c[i])cnt++;
		else cnt=0;
		maxs=max(maxs,cnt);
	}
	cout<<maxs;
	return 0;
}
