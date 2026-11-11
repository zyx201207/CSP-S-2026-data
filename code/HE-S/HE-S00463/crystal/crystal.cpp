#include<bits/stdc++.h>
using namespace std;
int sun=1,l=1,s=0;
int n,m,a[50000000],b[50000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				sun++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]>a[j]){
				int o=a[i];
				a[i]=a[j];
				a[j]=o;
			}
		}
	}
	for(int j=1;j<=n;j++){
		for(int z=0;z<m;z++){
			int h=a[j]+z;
			int k=a[j+1]+(m-z);
			if(h==k && h==a[j+2] && k==a[j+2]){
				sun=sun+2;
			}
		}
		b[l]=sun;
		l++;
	}
	
	for(int i=1;i<=l;i++){
		s=max(b[i],s);
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
