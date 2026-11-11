#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	bool q=1;
	long long sum=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long shu;
		char mu;
		cin>>shu>>mu;
		ans+=shu;
		if(mu!=a[0] && i!=1) q=0;
		if(shu<1000000000) while(shu--) a+=mu;
	}
	if(q || n==1) cout<<0;
	else if(ans>=1000000000) cout<<ans/2;
	else{
		for(int i=0,j=a.size()-1;i<a.size()/2;i++,j--){
			if(a[i]!=a[j]) sum++;
		}
		cout<<sum;
	}
	return 0;
}
