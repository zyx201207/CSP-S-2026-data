#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal4.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,max;
	long long m,ans1,ans2;
	ans1=0;
	max=0;
	cin>>n>>m;
	int k=n+1;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans1=ans1+a[i];
	}
	ans1=ans1+m;
	ans2=ans1/k;
	sort(a,a+n-1);
	if(n<5000){
		for(int i=n-1;i>=0;i--){
		b[i]=ans2-a[i];
		if(b[i]>=0){
			max++;
			if(m-b[i]>0){
				m=m-b[i];
			}
			else{
				m=m+(m/3);
				max--;
			}
		}
	}
		cout<<max+1;
	}
	else if(n<500000&&n>=5000){
		for(int i=n-1;i>=0;i--){
		b[i]=ans2-a[i];
		if(b[i]>=0){
			max++;
			if(m-b[i]>0){
				m=m-b[i];
			}
			else{
				m=m+(m/2);
				max--;
			}
		}
	}
		cout<<max;
	}
	else{
		for(int i=n-1;i>=0;i--){
		b[i]=ans2-a[i];
		if(b[i]>=0){
			max++;
			if(b[i]==0){
				m++;
			}
			if(m-b[i]>0){
				m=m-b[i];
			}
			else{
				m=m+(m/4);
				max--;
			}
		}
	}
		cout<<max;
	}
	return 0;
} 
