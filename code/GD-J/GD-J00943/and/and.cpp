#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int max=0,mm=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if((a[i]&a[j])>max)max=(a[i]&a[j]);
			}
		}
	}
	else if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]>max)max=a[i];
		}
	}
	else if(m==n){
		for(int i=0;i<n;i++){
			max&=a[i];
		}
	}
	else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					mm=(a[i]&a[j]);
					if((mm&a[k])>max)max=(mm&a[k]);
					mm=0;
				}
			}
		}
	}
	cout<<max;
	return 0;
}
