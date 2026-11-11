#include<bits/stdc++.h>
using namespace std;
int a[200010];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x=1;
	long long p=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>p) p=a[i];
	}
	if(m==1){
		cout<<p;
		return 0;
	}
	if(m==n){
		int y=a[1];
		for(int i=2;i<=n;i++){
			y=y&a[i];
		}
		cout<<y;
		return 0;
	}
	if(m==2){
		int h=0,v;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				v=a[i]&a[j];
				if(v>h) h=v;
			}
		}
		cout<<h;
		return 0; 
	}
	sort(a+1,a+1+n,cmp);
	int g=a[1];
	for(int i=2;i<=m;i++){
		g=g&a[i];
	}
	cout<<g;
	return 0;
} 
