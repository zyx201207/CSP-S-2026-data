#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
string s;
int ans=0;
int a[N];
char c[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num+=a[i];
		cin>>c[i];
	} 
	num/=2;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum>=num){
			sum=i;
			break;
		}
	}
//	cout<<s<<'\n';
//	for(int i=0;i<s.size()/2;i++){
//		cout<<s[i]<<' '<<s[s.size()-i-1]<<'\n';
//		if(s[i]!=s[s.size()-i-1]){
//			
//			ans++;
//		}
//	}
//	cout<<ans;
	int i=1,j=n;
	while(i<=sum&&j>=sum&&i<j){
		int minn=min(a[i],a[j]);
		if(c[i]!=c[j])ans+=minn;
		a[i]-=minn;
		a[j]-=minn;
		if(a[i]<=0){
			i++;
		}
		if(a[j]<=0){
			j--;
		}
	} 
	cout<<ans;
	return 0;
}
