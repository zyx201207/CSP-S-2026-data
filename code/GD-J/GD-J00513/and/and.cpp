#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,ans=-114514,a[maxn];
int count1(int num){
	int res=0;
	while (num){
		if (num&1)
			res++;
		num>>=1;
	}
	return res;
}
int dig(int num){
	int res=1;
	while (num){
		num>>=1;
	}
	return res;
}
bool cmp(int a,int b){
	if (count1(a)!=count1(b))
		return count1(a)>count1(b);
	for (int i=dig(a)-1;i>=0;i--){
		int ad=a>>i,bd=b>>i;
		if ((ad&1)!=(bd&1))
			return ad>bd;
	}
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for (int i=2;i<=m;i++)
		ans=ans&a[i];
	cout << ans;
	return 0;
}
