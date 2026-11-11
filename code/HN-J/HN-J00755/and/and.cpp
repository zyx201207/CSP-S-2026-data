#include<bits/stdc++.h>
using namespace std;
int a[200099]={};
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=0,s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	int maxn=-99999;
	int p=0;
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<n;j++){
				p=(a[i] && a[j]);
				if(p>maxn) maxn=p;
			}
		}
	}
	if(m==n){
		p=(a[1] && a[2]);
		for(int i=3;i<=n;i++){
			p=p && a[i];
		}
		maxn=p;
	}
	if(m>2 && m<n){
		p=(a[1] && a[2]);
		for(int i=3;i<=n;i++){
			for(int j=i+1;j<n;j++){
				for(int z=0;z<m;z++){
					p=(p && a[j+z]);
				}
				if(p>maxn) maxn=p;
			}
		}
	}
	cout<<maxn;
	return 0;
}
