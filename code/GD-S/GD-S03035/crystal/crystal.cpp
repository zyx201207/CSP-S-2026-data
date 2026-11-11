#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100006],s[100006],b[103],cnt,mx=-100006;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==0){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]){
				cnt++;
				mx=max(cnt,mx);
			}
			else cnt=0;	
		}
		cout<<mx+1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			s[i]+=a[i]-a[j];
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i]==m){
			cout<<i+b[a[i]]-1;
			return 0;
		}
	}
	return 0;
}
