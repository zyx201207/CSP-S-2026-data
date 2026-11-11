//GZ-J00291，石鑫，凯里市第十三中学 
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//string s;
	long long n,a[200005];
	cin>>n;
	char c[200005];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		//cout<<a<<' '<<c<<'\n';
		/*for(;a--;){
			s=s+c;
		}*/
	}
	//cout<<s<<'\n';
	long long l=1,r=n,ans=0;
	for(;l<r;){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
		}
		long long t=a[l];
		a[l]-=a[r];
		a[r]-=t;
		if(a[l]<=0)l++;
		if(a[r]<=0)r--;
	}
	cout<<ans;
	return 0;
}
