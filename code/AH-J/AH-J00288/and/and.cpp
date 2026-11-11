#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mx,mx2;
bool fl=true,fl2=true;
bool cmp(int x,int y){
	return x>y;
}
bool check(int x){
	int s=1;
	for(int i=0;i<=20;i++){
		if(i!=0)s*=2;
		if(x!=s-1)return true;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)fl=false;
		if(check(a[i]))fl2=false;
	}
	sort(a+1,a+n+1,cmp);
	if(fl||m==n||fl2){
		mx=a[1];
		for(int i=2;i<=n;i++)mx=mx&a[i];
	}else if(m==1){
		mx=a[1];
	}else if(m==2){
		for(int i=2;i<=n;i++)mx=max(mx,a[i]&a[i-1]);
	}else if(m==n-1){
		mx=a[1],mx2=a[2];
		for(int i=2;i<n;i++)mx=mx&a[i];
		for(int i=3;i<=n;i++)mx2=mx2&a[i];
		mx=max(mx,mx2);
	}else{
		for(int i=1;i<=n-m+1;i++){
			mx2=a[i];
			for(int j=i;j<i+m;j++){
				mx2=mx2&a[j];
			}
			mx=max(mx,mx);
		}
	}
	cout<<mx;
	return 0;
}
