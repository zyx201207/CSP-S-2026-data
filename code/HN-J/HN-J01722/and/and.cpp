#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s=-1,maxs=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)
			s=max(s,a[i]);
		cout<<s;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				s=max(s,a[i]&a[j]);
		}
		cout<<s;
		return 0;
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int l=j+1;l<=n;l++)
					s=max(s,a[i]&a[j]&a[l]);
			}
		}
		cout<<s;
		return 0;
	}
	else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int l=j+1;l<=n;l++){
					for(int k=l+1;k<=n;k++)
						s=max(s,a[i]&a[j]&a[l]&a[k]);
				}
			}
		}
		cout<<s;
		return 0;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			s=a[1];
			if(i==1)s=a[2];
			for(int j=1;j<=n,j!=i;j++)
				s=s&a[j];
			maxs=max(maxs,s);
		}
		cout<<maxs;
		return 0;
	}
	else{
		s=a[1];
		for(int i=2;i<=n;i++)
			s=s&a[i];
		cout<<s;
	}
	return 0;
}
