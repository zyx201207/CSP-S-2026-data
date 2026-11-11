#include<bits/stdc++.h>
using namespace std;
int a[200001],n,m,ans=0;
int h(int a,int b){
	string x,y,s;
	int sum=0;
	while(a!=0){
		x=char(a%2+'0')+x;
		a/=2;
	}
	while(b!=0){
		y=char(b%2+'0')+y;
		b/=2;
	}
	int k=min(x.size(),y.size())-1;
	for(int i=0;i<=k;i++){
		if(x[k-i]==y[k-i])s=x[k-i]+s;
		else s='0'+s;
	}
	if(s.empty())return 0;
	else{
		for(int i=0;i<s.size();i++){
			sum+=(s[k-i]-'0')*pow(2,i);
		}
		return sum;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++){
			ans=max(ans,h(a[i],a[j]));
		}
	}
	cout<<ans;
	return 0;
}
