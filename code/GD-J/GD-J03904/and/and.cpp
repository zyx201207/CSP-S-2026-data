#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf(" %d",&a[i]);
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}
	else if(m==n&&n>=5){
		int sc=a[0];
		for(int i=1;i<n;i++){
			sc&=a[i];
		}
		cout<<sc;
	}
	else if(m==2){
		int sc=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int o=a[i]&a[j];
				if(o>sc) sc=o;
			}
		}
		cout<<sc;
	}
	else if(m==n-1&&n>=5){
		int sc=0;
		for(int i=1;i<n;i++){
			int o=a[0];
			for(int j=1;j<n;j++){
				if(j==i) continue;
				else{
					sc&=a[j];
				}
			}
			if(o>sc) sc=o;
		}
		cout<<sc;
	}
	else if(m==3){
		int sc=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int o=a[i]&a[j]&a[k];
					if(o>sc) sc=o;
				}
			}
		}
		cout<<sc;
	}
	else{
		int sc=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(intl=k+1;l<n;l++){
						int o=a[i]&a[j]&a[k]&a[l];
						if(o>sc) sc=o;
					}
				}
			}
		}
		cout<<sc;
	}
	return 0;
}
