#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i,maxa=-1,temp,z=0,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(i=1;i<=n;i++){
			if(a[i]>maxa){
				maxa=a[i];
			}
		}
		cout<<maxa;
		return 0;
	}
	else if(m==n){
		maxa=a[1];
		for(i=2;i<n;i++){
			maxa=(maxa&a[i]);
		}
		cout<<maxa;
		return 0;
	}
	else if(m==2){
		for(i=1;i<n;i++){
			for(j=i+1;j<=n;j++){
				if((a[i]&a[j])>maxa){
					maxa=a[i]&a[j];
				}
			}
		}
		cout<<maxa;
		return 0;
	}
	else if(m==n-1){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				if(z==0){
					temp=a[j];
					z++;
					continue;
				}
				temp=(temp&a[j]); 
			}
			if(temp>maxa)maxa=temp;
		}
		cout<<maxa;
		return 0;
	}
	else{
		sort(a+1,a+n+1);
		maxa=a[n];
		for(i=n-1;i>n-m;i--){
			maxa=(maxa&a[i]);
		}
		cout<<maxa;
		return 0;
	}
	return 0;
}
