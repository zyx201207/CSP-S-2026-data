#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	int n,f=0;
	long long sum=0;
	cin>>n;
	cin>>a[1]>>c[1];
	sum=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]&&f==0) f=0;
		else f=1;
		sum+=a[i];
	}
	if(f==0){
		cout<<0;
	}
	else{
		cout<<sum/2;
	}
	return 0;
}
