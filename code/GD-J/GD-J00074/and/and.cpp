#include<bits/stdc++.h>
using namespace std;
long long a1[100000]={};

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a1[i];
	}
	long long max1=-1;
	long long sum=1;
	if(m==1){
		for(int i=0;i<n;i++){
			sum=a1[i];
			max1=max(max1,sum);
		}
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				sum=a1[i]^a1[j];
				max1=max(max1,sum);
			}
		}
	}
	else if(m==n-1){

	long long min1=100000000;
	long long sum1=0;
	long long sum=0;
	long long min2=0;
		for(int i=0;i<n;i++){
			sum1=a1[i];
			if(min1>sum1)
			{
				min1=min(sum1,min1);
				min2=i;
			}
			sum+=a1[i];
		}
		int x=a1[0];
		for(int i=1;i<n;i++)
		{if(i!=min2) x=x^a1[i];
		}
		max1=x;
	}
	else{
		int x=a1[0];
		for(int i=1;i<n;i++){
			x=x^a1[i];
		}
		max1=x;
	}
	cout<<max1;
}
