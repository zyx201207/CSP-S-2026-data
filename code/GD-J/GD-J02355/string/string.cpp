#include<iostream>
#define ll long long
using namespace std;
const int N=200005;
int a[N];
char c[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	ll ans=0;
	for(int i=1,j=n;i<j;){
		int tmp=min(a[i],a[j]);
		if(c[i]!=c[j])ans+=tmp;
		a[i]-=tmp;
		a[j]-=tmp;
		if(!a[i])i++;
		if(!a[j])j--;
	}
	cout<<ans;
	return 0;
} 
/*
3
3 a
2 b
2 a
1
*/
