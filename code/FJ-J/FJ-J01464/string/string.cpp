#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char b[200010];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(b[i]!=b[i-1]&&i!=1){
			flag=0;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]<a[r]){
			if(b[l]!=b[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}else{
			if(b[l]!=b[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}
//ÎÒÊÇtc
//9:13
//Ô¤ÆÚ100 
