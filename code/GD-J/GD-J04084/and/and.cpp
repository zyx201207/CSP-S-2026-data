#include <bits/stdc++.h>
using namespace std; 
int a[20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum++;
	}
	if(m=1){
		int max=0;
		for(int i=0;i<sum;i++){
			if(a[i]>max) max=a[i];
		}
		cout<<max;
		return 0;
	}
	if(m=2){
	    int max=0;
		for(int i=0;i<sum;i++){
			for(int j=0;j<sum;j++){
				if((a[i]&a[j])>max) max=a[i]&a[j];
			}
		}
		cout<<max;
		return 0;
	}
	if(m=3){
		int max =0;
		for(int i=0;i<sum;i++){
			for(int j=0;j<sum;j++){
				for(int k=0;k<sum;k++){
					if((a[i]&a[j]&a[k])>=max) max=a[i]&a[j]&a[k];
				} 
			}
		}
		cout<<max;
		return 0;
	}
	if(m=4){
		int max =0;
		for(int i=0;i<sum;i++){
			for(int j=0;j<sum;j++){
				for(int k=0;k<sum;k++){
					for(int l=0;l<sum;l++){
						if((a[i]&a[j]&a[k]&a[l])>=max) max=a[i]&a[j]&a[k]&a[l];
					}	
				} 
			}
		}
		cout<<max;
		return 0;
	}
	if(m=5){
		int max =0;
		for(int i=0;i<sum;i++){
			for(int j=0;j<sum;j++){
				for(int k=0;k<sum;k++){
					for(int l=0;l<sum;l++){
						for(int h=0;h<sum;h++){
							if((a[i]&a[j]&a[k]&a[l]&a[h])>=max) max=a[i]&a[j]&a[k]&a[l]&a[h];
						}
					}	
				} 
			}
		}
		cout<<max;
		return 0;
	}
	sort(a,a+sum);
	int tt=0;
	for(int i=0;i<=n;i++){
		tt=tt&a[sum-i-1];
	}
	cout<<tt;
    return 0;
} 
