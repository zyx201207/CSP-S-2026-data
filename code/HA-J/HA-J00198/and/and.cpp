#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[700005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==m){
		b[0]=a[0];
		for(int i=1;i<n;i++) b[i]=b[i-1]&a[i];
		cout<<b[n-1];
		return 0;
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	}
	if(m==2){
		int k=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				b[k]=a[i]&a[j];
				k++;
			}
		}
		sort(b,b+k);
		cout<<b[k-1];
	}
	if(m==3){
		int k=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int l=j+1;l<n;l++){
					b[k]=a[i]&a[j]&a[l];
					k++;
				}
			}
		}
		sort(b,b+k);
		cout<<b[k-1];
	}
	if(m==4){
		int k=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int l=j+1;l<n;l++){
					for(int o=l+1;o<n;o++){
						b[k]=a[i]&a[j]&a[l]&a[o];
						k++;
					}
				}
			}
		}
		sort(b,b+k);
		cout<<b[k-1];
	}
	if(m==5){
		int k=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int l=j+1;l<n;l++){
					for(int o=l+1;o<n;o++){
						for(int p=o+1;p<n;p++){
							b[k]=a[i]&a[j]&a[l]&a[o]&a[p];
							k++;
						}
					}
				}
			}
		}
		sort(b,b+k);
		cout<<b[k-1];
	}
	return 0;
}
