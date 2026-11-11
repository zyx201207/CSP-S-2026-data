/*#include <bits/stdc++.h>
using namespace std;
int n,m,a[200001][2]={},ans=-1;
void fd(int step,int f){
	if(!step){
		ans=max(ans,f);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i][1]) continue;
		a[i][1]=1;
		fd(step-1,f&a[i][0]);
		a[i][1]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
	}
	if(m==n){
		for(int i=2;i<=n;i++) a[i][0]&=a[i-1][0];
		cout<<a[n][0];
	}
	else if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i][0]);
		cout<<ans;
	}
	else{
		fd(m,pow(2,20));
		cout<<ans;
	}
	return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200001]={},ans=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) a[i]&=a[i-1];
	for(int i=1;i<=n-m;i++) ans=max(ans,a[i]|a[i+m]);
	cout<<ans;
	return 0;
}


