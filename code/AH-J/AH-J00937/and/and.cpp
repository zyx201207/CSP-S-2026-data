#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000];
int dfs(int x){
	int d;
	if(x==1){
		d=a[2];
		for(int i=3;i<=n;i++)
			d=d&a[i];
	} 
	else{
		d=a[1];
		for(int i=2;i<=n;i++)
			if(!(x==i))
				d=d&a[i];
	}
	return d;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++)
			if(a[i]>mx)
				mx=a[i];
		cout<<mx;
	}
	else if(m==n){
		int s=a[1]&a[2];
		for(int i=3;i<=n;i++)
			s=s&a[i];
		cout<<s;
	}
	else if(m==2){
		int s,mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s=a[i]&a[j];
				if(s>mx)
					mx=s;
			}
		}
		cout<<mx;
	}
	else if(m==n-1){
		int mx=0;
		for(int i=1;i<=n;i++)
			mx=max(mx,dfs(i));
		cout<<mx;
	}
	return 0;
}
