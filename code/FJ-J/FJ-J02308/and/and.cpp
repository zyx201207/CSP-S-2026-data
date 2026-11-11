#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],ans1,ans2;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a-1,a+n);
	if(n<=20){
		ans1=a[n-1];
		for(int i=n-2;i>n-m-1;i--){
			ans1=(ans1&a[i]);
		}
		ans2=a[n-2];
		for(int i=n-3;i>n-m-2;i--){
			ans2=(ans2&a[i]);
		}
		cout<<max(ans1,ans2);
	}
	else{
		ans1=a[n-1];
		for(int i=n-2;i>n-m-1;i--){
			ans1=(ans1&a[i]);
		}
		ans2=a[n-2];
		for(int i=n-3;i>n-m-2;i--){
			ans2=(ans2&a[i]);
		}
		int ans3=a[n-3];
		for(int i=n-4;i>n-m-3;i--){
			ans3=(ans3&a[i]);
		}
		int ans4=a[n-4];
		for(int i=n-5;i>n-m-4;i--){
			ans4=(ans4&a[i]);
		}
		int ans5=a[n-5];
		for(int i=n-6;i>n-m-5;i--){
			ans5=(ans5&a[i]);
		}
		cout<<max(ans1,max(ans2,max(ans3,max(ans4,ans5))));
	}
	return 0;
}
