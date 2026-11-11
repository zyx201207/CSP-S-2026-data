#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=0;int m=0;int num=0;int h=0;
	cin>>n>>m;int a[n];int q=0;
	int b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//sort(a,a+n);
	for(int i=0;i<n;i++){
		q=m;
		num=0;
		for(int j=0;j<n;j++)
		{
			if((a[j]<=a[n-1])&&q>=0)
			{
				num+=1;
				q=q-(a[n-1]-a[j]);
			}
			if(q<0)
			{
				num--;
				for(int k=j+1;j<n;k++)
				{
					if(a[k]==a[n-1])
					{
						num++;
					}
				}	
			}
		}
		cout<<num<<" "; 
		n--;
		b[i]=num;
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(b[i]>b[i+1]){
				h=b[i];
				b[i]=b[i+1];
				b[i+1]=h; 
			}
		}
	}
	cout<<b[n-1];
	return 0;
}
