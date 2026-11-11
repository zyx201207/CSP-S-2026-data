#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long b[200000];
	char d[200000];
	for(int i=0;i<n;i++){
		cin>>b[i]>>d[i];
	}
	long long sum=0;
	int i=0,j=n-1;
	while(i<j){
		if(b[i]==0){
			i++;
		}
		if(b[j]==0){
			j--;
		}
		if(b[i]<b[j]&&d[i]!=d[j]){
			sum=sum+b[i];
			b[i]=b[i]-b[i];
			b[j]=b[j]-b[i];
		}else if(b[i]>=b[j]&&d[i]!=d[j]){
			sum=sum+b[j];
			b[i]=b[i]-b[j];
			b[j]=b[j]-b[j];
		}else if(b[i]>=b[j]&&d[i]==d[j]){
			b[i]=b[i]-b[j];
			b[j]=b[j]-b[j];
		}else if(b[i]<b[j]&&d[i]==d[j]){
			b[i]=b[i]-b[i];
			b[j]=b[j]-b[i];
		}
	}
	cout<<sum;
	return 0;
}
