#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum=1,sum1=1,sum2=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			sum=a[1];
			sum1=a[1];
		}
		if(i==2){
			sum2=a[2];
		}
		if(i>2){
			sum2=sum2&a[i];
		}
		if(i!=1){
			sum=a[i]&sum;
		}
		if(i!=1&&i<n){
			sum1=sum1&a[i];
		}
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==n){
		cout<<sum;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==2){
		cout<<a[n-1];
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==n-1){
		if(sum1>sum2){
			cout<<sum1;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}else{
			cout<<sum2;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
