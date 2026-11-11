#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
string bin(int o){
	char a[1005];
	int dgt=0;
	while(o){
		a[dgt]=char(o%2+48);
		dgt++;
		o/=2;
	}
	string b=a;
	for(int i=0;i<b.size();i++)a[i]=b[b.size()-i-1];
	return a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==1){
		int mx=0;
		for(int i=0;i<n;i++){
			if(a[i]>mx)mx=a[i];
		}
		cout<<mx;
		return 0;
	}
	cout<<a[n-1];
	return 0;
}

