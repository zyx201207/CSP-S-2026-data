#include<bits/stdc++.h>
using namespace std;
const long long MAXN=500005;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0,mubiao=0;
	int ans=0; 
	cin>>n>>m;
	int a[MAXN];
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		ans+=a[i];
	}
	sort(a+1,a+n+1);
	int minn=a[n],qnq=0,aaa=0,mubiao1=0,minn1;
	ans=(abs(ans+m)+n-1)/n;
	for(int i=1;i<=n;i++) {
		int qwq1=0;
		if(a[i]<0) {
			aaa=qnq;
			mubiao1=mubiao;
			minn1=minn;
		}
		qwq1=abs(a[i])-ans;
			if(abs(qwq1)<minn) {
				mubiao=a[i];
				minn=abs(qwq1);
				qnq=i;
				if(a[i]<0) {
					qnq=aaa;
					mubiao=mubiao1;
					minn=minn1;
				}
			} 
	}
	for(int i=qnq;i>=1;i--) {
		int cha=mubiao-a[i];
		a[i]+=cha;
		m-=cha;
		if(m<0) {
			break;
		}
	}
	for(int i=1;i<=n;i++) {
		if(a[i]==mubiao) sum++;
	}
	cout<<sum;
	return 0;
}
