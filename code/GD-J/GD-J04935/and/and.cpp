#include <bits/stdc++.h>
using namespace std;
int n,m,a[2*114514],ans=0,len;
int num[2*114514][33];
void zhuanhuan(int xb,int x){
	int j=1;
	while(x>0){
		num[xb][j]=x%2;
		x/=2;
		j++;
	}
	len=max(j-1,len);
//	for(int k=j-1;k>=1;k--)cout << num[xb][k];
//	puts("");
}
int main(){
//	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout << a[n];
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++)a[1]=a[1]&a[i];
		cout << a[1];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n-1;i++)for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		cout << ans;
		return 0;
	}
	for(int i=1;i<=n;i++)zhuanhuan(i,a[i]);
	set <int> s1;
	s1.clear();
	for(int i=1;i<=n;i++)s1.insert(i);
	for(int i=len;i>=1;i--){
		set <int> s2;
		s2.clear();
		for(auto it=s1.begin();it!=s1.end();it++)
			if(num[*it][i]==1)s2.insert(*it);
//		cout << s2.size() << endl;
		if(s2.size()>=m){
			ans+=pow(2,i-1);
			s1.clear();
			for(auto it=s2.begin();it!=s2.end();it++)s1.insert(*it);
		}
	}
	cout << ans;
	return 0;
}


