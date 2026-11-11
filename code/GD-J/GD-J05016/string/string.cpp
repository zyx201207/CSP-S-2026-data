#include<iostream>
using namespace std;
const int N=2e5+10;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,sum1=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		sum1=sum+1;
		int geshu;
		char zifu;
		cin>>geshu>>zifu;
		sum+=geshu;
		for(int j=sum1;j<=sum;j++){
			c[j]=zifu;
		}
	}
	int sum2=sum/2;
	for(int i=1;i<=sum2;i++){
		if(c[i]!=c[sum-i+1])ans++;
	} 
	cout<<ans;
	return 0;
}
