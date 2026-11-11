#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N],s[N];
bool cmp(int a,int b){
	return a<b;
}
int ans(int i){
	for (int j=0;j<n;j++){
		if (a[i]==a[j]) s[j]=-1;
		else if (a[j]>a[i]) s[j]=a[j]-a[i];
		else s[j]=a[i]-a[j];
	}
	sort(s,s+n,cmp);
	int m1=m,ans_=0,j=1;
	while (m1>=0){
		m1-=s[j];
		ans_++;
		j++;
	}
	return ans_;
}
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans_=0;
	for (int i=0;i<n;i++){
		ans_=max(ans_,ans(i));
	}
	cout<<ans_;
	return 0;
}
