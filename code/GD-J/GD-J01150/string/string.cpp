#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans,a[200010],b[200010],L=0,o=0;
string s[200010],c[200010];
int main(){
	freopen("string.in" ,"r",stdin );
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>b[i];
		cin>>s[i];
		L+=b[i];
	}
	for(int i=1;i<=m;++i){
		if(o<=L/2&&o+b[i]>=(L+1)/2){
			if(o!=L/2){
				n++;
				a[n]=L/2-o;
				c[n]=s[i];
			}
			if(o+b[i]!=(L+1)/2){
				n++;
				a[n]=o+b[i]-(L+1)/2;
				c[n]=s[i];
			}
			o+=b[i];
			continue;
		}
		n++;
		a[n]=b[i];
		c[n]=s[i];
		o+=b[i];
	}
//	for(int i=1;i<=n;++i){
//		cout<<a[i]<<" "<<c[i]<<'\n';
//	}
	for(int i=1,j=n;i<=j;){
		if(c[i]!=c[j])ans+=min(a[i],a[j]);
		if(a[i]>a[j])a[i]=a[i]-a[j],j--;else
		if(a[i]<a[j])a[j]=a[j]-a[i],i++;else
		if(a[i]==a[j])i++,j--;
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
