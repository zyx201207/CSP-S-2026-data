#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		int max=-1;
		for(int i=0;i<n;i++){
			int n;
			cin>>n;
			max=n>max?n:max;
		}
		cout<<max;
		return 0; 
	}
	if(m==n){
		int sum=2147483647;
		for(int i=0;i<n;i++){
			int n;
			cin>>n;
			sum=sum&n;
		}
		cout<<sum;
		return 0; 
	}
	if(n<=2000){
		int a[25];
		int max=-1;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int a1,b1;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				a1=a[i]&a[j]>max?i:a1;
				b1=a[i]&a[j]>max?j:b1;
				max=a[i]&a[j]>max?a[i]&a[j]:max;
			}
		}
		a[a1]=0;
		a[b1]=0;
		a1=-1;
		int c=max;
		max=-1;
		for(int i=0;i<m-2;i++){
			for(int j=0;j<n;j++){
				a1=c&a[j]>max?j:a1;
				max=c&a[j]>max?c&a[j]:max;
			}
		}
		cout<<max;
	}
	return 0;
}


