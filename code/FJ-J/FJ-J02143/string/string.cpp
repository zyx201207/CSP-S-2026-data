#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum,ans,p[200010];
char s[200010];
char f(int w){
	int l=0,z=0;
	while(l<w){
		z++;
		l+=a[z];
	}
	return s[z];
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	else if(n==2&&s[1]!=s[2]){
		cout<<min(a[1],a[2]);
		return 0;
	}else{
		for(int i=1;i<=sum/2;i++){
			if(f(i)!=f(sum-i+1)) ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
