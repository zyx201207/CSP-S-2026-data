//GZ-J00640 遵义市第四初级中学 马骎骎 
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int n,m;
	cin>>n>>m;
	long long int a[n+1];
	for(long long int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
//	for(long long int i=0;i<n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	long long int max=0,t=-1;
	for(long long int i=0;i<n-m+1;i++){
		for(long long int j=i;j<i+m;j++){
			t&=a[j];
		}
		if(t>=max){
			max=t;
		}
//		cout<<t<<" "<<max<<endl;
		t=-1;
	} 
	cout<<max;
	
	return 0;
}

