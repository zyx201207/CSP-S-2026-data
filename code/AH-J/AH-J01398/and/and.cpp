#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int p,int q){
	return p>q;
}
bool panduan(int ff){
	while (ff){
		if (ff%2==1&&ff!=1) {
			return false; 
		}
		else ff/=2;
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort (a+1,a+n+1,cmp);
	for (int i=m;;i++){
		if (a[i-1]>=a[i]*2&&panduan(a[i])) m++;
		else if (panduan(a[i-1])) m++;
		else break;
	}
	cout<<a[m]<<"\n";
	return 0;
}

