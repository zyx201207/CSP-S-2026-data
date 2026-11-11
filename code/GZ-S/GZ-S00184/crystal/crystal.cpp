//GZ-S00184 华东师范大学附属贵阳学校 袁琬潇 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],cf[N],ans,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool f=1;
	for(int i=1;i<n;i++){
		cf[i]=max(a[i],a[i+1])-min(a[i],a[i+1]);
		if(cf[i]!=cf[i-1]&&i>=2) f=0;
	}
	if(f==1){
		for(int i=1;m>0;i++){
			ans=ans+a[i+1]-a[i];
			m=m-ans;
			cnt++;
		}
		cout<<cnt+1<<endl;
		return 0;
	}else{
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++){
			cf[i]=a[i+1]-a[i];
		}
		long long maxn=0;
		for(int i=2;i<=n;i++){
			long long num=m,ans=0,cnt=0;
			for(int j=i;;j--){
				if(j<1||num<0) break;
				num-=ans;
				if(num<0) break;
				cnt++;
				ans+=cf[j-1];
			}
			if(cnt>=maxn) maxn=cnt;
		}
		cout<<maxn<<endl;
	}
	return 0;
}
