#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a.begin(),a.end(),cmp);
		cout<<a[0];
	}
	if(m==2){
		int max=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(max<a[i]&a[j])
					max=a[i]&a[j];
			} 
		}
		cout<<max;
	}
	if(m==3){
		int max=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					if(max<a[i]&a[j]&a[k])
						max=a[i]&a[j]&a[k];
				}
			} 
		}
		cout<<max;
	}
	if(m==4){
		int max=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						if(max<a[i]&a[j]&a[k]&a[l])
							max=a[i]&a[j]&a[k]&a[l];
					}
				}
			} 
		}
		cout<<max;
	}
	if(m==5){
		int max=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int m=l+1;m<n;m++){
						if(max<a[i]&a[j]&a[k]&a[l]&a[m])
							max=a[i]&a[j]&a[k]&a[l]&a[m];
						}
					}
				}
			} 
		}
		cout<<max;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
