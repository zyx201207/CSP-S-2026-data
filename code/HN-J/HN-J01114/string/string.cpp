#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n;
long long ans;
int a[N];
string c[N],S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	} 
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	if(c[1]==c[n]){
		if(a[1]>a[n]){
			a[1]=a[1]-a[n];
			a[n]=0;
		}
		else{
			a[n]=a[n]-a[1];
			a[1]=0;
		}
	}
	else{
		ans+=min(a[1],a[n]);
		if(a[1]>a[n]){
			a[1]=a[1]-a[n];
			a[n]=0;
		}
		else{
			a[n]=a[n]-a[1];
			a[1]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			S+=c[i];
		}
	}
	for(int i=0;i<S.length()/2;i++){
		if(a[i]!=a[S.length()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
