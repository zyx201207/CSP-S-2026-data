#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],ans;
string s,s2;
bool flag;
void pd(int r){
	if(r==0){
		s2=s;
		return;
	}
	s+=r%2;
	pd(r/2);
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	flag=1;
	for(int i=0;i<n;i++){
		s="";
		pd(a[i]);
		for(int j=0;j<s2.size();j++){
			if(s2[j]=='0'){
				flag=0;
				break;
			}
		}
	}
	if(flag){
		sort(a,a+n);
		cout<<a[n-2];
		return 0;
	}
	if(n==m){
		ans=a[0];
		for(int i=0;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		sort(a,a+n);
		for(int i=0;i<n;i++){
			if(a[i]==a[i+1]){
				ans=max(a[i],ans);
			}
		}
		long long maxx=ans;
		ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				long long f=a[i]&a[j];
				ans=max(ans,f);
			}
		}
		ans=max(ans,maxx);
		cout<<ans;
		return 0;
	}
	
	return 0;  
}
