#include<iostream>
using namespace std;
int n,a[200003];
char c[200003];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		int x=min(a[i],a[j]);
		if(c[i]!=c[j])ans+=x;
		a[i]-=x;a[j]-=x;
		if(!a[i])i++;
		if(!a[j])j--;
	}
	cout<<ans;
	return 0;
}
