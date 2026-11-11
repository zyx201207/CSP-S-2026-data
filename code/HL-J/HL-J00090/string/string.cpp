#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],sum;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int i=1,last=n,x;
	while(true){
		x=min(a[i],a[last]);
		if(a[i]==a[last]){
			if(s[i]!=s[last])sum+=x;
			i++,last--;
		}
		else if(x==a[i]){
			if(s[last]!=s[i])sum+=x;
			i++,a[last]-=x;
		}
		else{
			if(s[last]!=s[i])sum+=x;
			last--,a[i]-=x;	
		}
		if(i>last) break;
	}
	cout<<sum;
	return 0;
}
