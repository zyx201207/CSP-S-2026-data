#include<bits/stdc++.h>
using namespace std;
long long a[500005];
string b[500005];
string jz(int x){
	int cnt=x;
	string fs,s;
	while(cnt<1){
		fs+=cnt%2;
		cnt/=2;
	}
	int l=fs.size()-1;
	for(int i=0;i<=l;i++){
		s[l-i]=fs[i];
	}return s;
}//二进制（暂时无用） 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];//b[i]=jz(a[i]);	
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<cout<<a[n]<<"\n";
	}else if(m==n){
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<"\n";
	}else if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<"\n";
	}else cout<<a[n+1-m]<<"\n";
	return 0;
}
