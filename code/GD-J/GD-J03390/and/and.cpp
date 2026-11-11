#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	int su=a[1];
	if(m==n){
		for(int i=2;i<=m;i++){
			su=su&a[i];
		}
	}
	int s=0;
	if(m==2){
		for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		if(a[i]&a[j]>s){
			s=a[i]&a[j];
		}
	}
	}
	}
	if(m==3){
		for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int k=j+1;k<=n;k++){
			if(a[i]&a[j]&a[k]>s){
			s=a[i]&a[j]&a[k];
		}	
		}
		
	}	
	}
	}
	if(m==4){
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int a1=k+1;a1<=n;a1++)
		if(a[i]&a[j]&a[k]&a[a1]>s)
		s=a[i]&a[j]&a[k]&a[a1];
	}
	cout<<s;
}
