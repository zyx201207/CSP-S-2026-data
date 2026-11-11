#include<bits/stdc++.h>
using namespace std;
struct qwe{
	long long number;
	char c;
}a[200005];
long long n,ans;
bool f1,f2,f3;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].number>>a[i].c;
		if(i>=2&&a[i].number!=a[i-1].number) f2=1;
		if(i>=2&&a[i].c!=a[i-1].c) f3=1;
	} 
	for(int i=1;i<=(n+1)/2;i++){
		if(a[i].c==a[n-i].c) f1=1;
		else f1=0;
	}
	if(f1==1){
		if(f2==0||f3==0){
			cout<<0<<endl;
			return 0;
		}
		if(f2==1){
			for(int i=1;i<=(n+1)/2;i++){
				ans+=a[i].number-a[n-i].number;
			}
			cout<<ans<<endl;
			return 0;
		}
	}
	else if(f2==0){
		for(int i=1;i<=(n+1)/2;i++){
			if(a[i].c!=a[n-i].c) ans+=a[i].number;
		}
		cout<<ans<<endl;
		return 0;
	}
	else{
		for(int i=(n+1)/2;i<=n;i++){
			ans+=a[i].number;
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
