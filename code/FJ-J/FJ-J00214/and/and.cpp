#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],cnt,maxn;
int aaa(int x1,int x2){
	int ans=1,sum=0;
	string s1="",s2="";
	while(x1>0){
		s1+=(char(x1%2)+'0');
		x1/=2;
	}
	while(x2>0){
		s2+=(char(x2%2)+'0');
		x2/=2;
	}
	int l1=s1.size(),l2=s2.size();
	for(int i=0;i<=min(l1,l2);i++){
		if(s1[i]=='1'&&s2[i]=='1'){
			for(int j=1;j<=i;j++) ans*=2;
			sum+=ans;
			ans=1;
		}
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	for(int i=n;i>=m;i--){
		cnt=a[i];
		for(int j=i;j>=i-m;j--) cnt=aaa(cnt,a[j]);
		maxn=max(cnt,maxn);
	}
	cout<<maxn;
	return 0;
}
