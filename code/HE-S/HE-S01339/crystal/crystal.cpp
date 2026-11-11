#include<bits/stdc++.h>
using namespace std;
	long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[100001];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int num[100001];
for(int i=0;i<n;i++){

	for(int j=0;j<n;j++){
		if(a[i]>=a[j]){
			num[i]+=a[i]-a[j];
		}else{
			num[i]+=a[j]-a[i];
		}

	}
	
}
int minx=100001;
int xiab=0;
for(int i=0;i<n;i++){
	if(num[i]<=minx){

		minx =num[i];
		xiab=i;
		}
	
}
int ans=m;
for(int i=0;i<m;i++){
	if(ans>=a[xiab]-a[i]&&a[i]<a[xiab]){
		a[i]=a[xiab];
		ans-=a[xiab]-a[i];
	}
}
int sum=0;
for(int i=0;i<n;i++){
	if(a[i]==a[xiab]){
		sum++;
	}
}
cout<<sum;




	fclose(stdin);
	fclose(stdout); 
	
	
	return 0;
}
