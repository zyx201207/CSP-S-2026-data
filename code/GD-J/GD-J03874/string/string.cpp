#include<iostream>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	char a[1000000];
	char s[1000000];
	int sum=0;
	int x[1000000];
	int sum1=0;
	int v=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		cin>>a[i];
		sum=sum+x[i];
		for(int j=1;j<=x[i];j++){
			v=v+1;
			s[v]=a[i];
		}
	}
	for(int i=1;i<=sum/2;i++){
		if(s[i]!=s[sum-i+1]){
			sum1=sum1+1;
			
		}
	}
	cout<<sum1;
	return 0;
}
