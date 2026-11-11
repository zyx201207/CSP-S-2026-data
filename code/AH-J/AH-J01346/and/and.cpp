#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005],ans1,ans2,ans3,s[200005],ans4,ans5;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans1=max(ans1,a[i]);
		if(i==1)ans2=a[i],s[i]=a[i];
		else ans2=ans2&a[i],s[i]=s[i-1]&a[i];
	}
	if(m==1){
		cout<<ans1;
		return 0;
	}
	if(m==n){
		cout<<ans2;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans3=max(ans3,a[i]&a[j]);
			}
		}
		cout<<ans3;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}
