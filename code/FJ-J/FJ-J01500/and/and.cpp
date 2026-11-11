#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
long long n,m,a[N],maxn,str,qmi[N]={1},sqmi[N]={1};
bool flag=1,flag1=1,flag2=1,flag3=1;
void dfs(int p,int t,long long s) {
//	cout<<p<<" "<<t<<" "<<s<<endl;
	if(t>=m) {
		maxn=max(maxn,s);
		return ;
	}
	if(p>n) return ;
	dfs(p+1,t,s);
	if(t==0) dfs(p+1,t+1,a[p]);
	else dfs(p+1,t+1,s&a[p]);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<32;i++)
		qmi[i]=qmi[i-1]*2,sqmi[i]=sqmi[i-1]+qmi[i];
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]==0) flag3=0;
		if(a[i]!=i-1) flag=0;
		if(a[i]>=4) flag1=0;
		int x=a[i]+1;
		while(x>1) {
			if(x%2==0) x/=2;
			else {
				flag2=0;
				break;
			}
		}
	}
	bool f=0;
	for(int i=0;i<32;i++)
		if(qmi[i]==n) {
			f=1;
			break;
		}
	if(!f) flag=0;
	str=a[1];
	for(int i=2;i<=n;i++)
		str&=a[i];
	sort(a+1,a+n+1,greater<int>());
	if(!flag3) {
		cout<<0;
		return 0;
	}
	if(m==1) {
		cout<<a[1];
		return 0;
	}
	if(m==n) {
		cout<<str;
		return 0;
	}
	if(flag2) {
		cout<<a[n];
		return 0;
	}
	if(n<=20) {
		dfs(1,0,0);
		cout<<maxn;
		return 0;
	}
	if(flag) {
		int xxx=n-m,pos1=0,pos2=0;
		for(int i=0;i<32;i++) {
			if(sqmi[i]>xxx) {
				pos1=i;
				break;
			}
		}
		for(int i=1;i<pos1;i++) {
			if(sqmi[pos1]-sqmi[i-1]<=xxx) {
				cout<<sqmi[pos1]-sqmi[i-1];
				break;
			}
		}
		cout<<pos1<<endl;
		return 0;
	}
	if(n<=5000) {
		if(m==2) {
			long long mx=0;
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					if(i==j) continue;
					else mx=max(mx,(a[i]&a[j]));
				}
			}
			cout<<mx;
		} else cout<<str;
		return 0;
	}
	return 0;
}
