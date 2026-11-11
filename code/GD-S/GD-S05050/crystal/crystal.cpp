#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0,m=0,mid1=0,mid2=0,num1=0,num2=0,middle=0;
	cin>>n>>m;
	long long a[n+1];;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}	
	}
	if(n%2==1){
		mid1=a[(n+1)/2];
		middle=(n+1)/2;
		mid2=a[(n-1)/2];
	}else{
		mid1=a[n/2];
		middle=n/2;
	}
	if(n%2==1){
		int h=m;
		for(int i=1;i<=middle;i++){
			if(h<(mid1-a[i])){
				break;
			}else{
				h=h-mid1+a[i];
				num1++;
			}
		}
		h=m;
		for(int i=1;i<=middle-1;i++){
			if(h<(mid2-a[i])){
				break;
			}else{
				h=h-mid2+a[i];
				num2++;
			}
		}
	}else{
		for(int i=1;i<=middle;i++){
			if(m<(mid1-a[i])){
				break;
			}else{
				m=m-mid1+a[i];
				num1++;
			}
			if(m<mid1-a[i]){
				break;
			}
		}
	}
	if(num1>num2){
	cout<<num1;
	}else{
	cout<<num2;	
 }
	return 0;
}
