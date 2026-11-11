#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],max1=-1,flag=1;
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
bool amp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
	}
	sort(a+1,a+1+n,amp);
	if(m==1){
		cout<<max1;
		return 0;
	}
	if(m==n){
		cout<<a[n];
		return 0;
}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int b=a[i]&a[j];
				max1=max(max1,b);
			}
		}
		cout<<max1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			flag=0;
			continue;
		}
	}
	if(flag) {
		cout<<1;
	}
	cout<<a[m];
	return 0;
}
