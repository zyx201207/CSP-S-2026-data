#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
string s;
long long sum=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i],sum+=a[i];
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	}
	s=' '+s;
	for(int i=1;i<=(sum+1)/2;i++){
		if(s[i]!=s[sum-i+1]) ans++;
	}
//	int l=1,r=n;
//	while(l<r){
//		if(c[l]==c[r]){
//			if(a[l]>a[r]) a[l]-=a[r],r--;
//			else if(a[l]==a[r]) l++,r--;
//			else a[r]-=a[l],l++;
//		}else{
//			if(a[l]>a[r]) a[l]-=a[r],ans+=a[r],r--;
//			else if(a[l]==a[r]) l++,r--,ans+=a[l];
//			else a[r]-=a[l],ans+=a[l],l++;
//		}
//	}
	cout<<ans;
}
