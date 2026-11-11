#include<bits/stdc++.h>
using namespace std;
long long m,n,s,ans,cnt,a[500003],b[500003];
bool mk=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(b[i]!=b[i-1]&&i>2)mk=false;
	}
	if(mk){
		while(m<n*(n-1)*b[2]/2)n--;
		cout<<n;
	}else{
		for(int i=1;i<n;i++){
			ans=0;
			for(int j=i+1;j<=n&&cnt<=m;j++){
				cnt+=(j-i)*b[j];
				ans++;
			}
			s=max(s,ans);
		}
		cout<<s;
	}
	return 0;
}
