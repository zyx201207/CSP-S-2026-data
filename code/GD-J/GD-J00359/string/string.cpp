#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0;
	long long sum=0,d=0,e=0;
	cin>>n;
	vector<int> a(n+1);
	vector<char> c(n+1);
	for(int i=1;i<n+1;i++)
	{
		cin>>a[i]>>c[i];
		d+=a[i];
	}
	long long f,j;
	f=1;
	j=n;
	while(0==0){
		k=0;
		if((a[f]>a[j])&&(c[f]!=c[j]))
		{
			a[f]-=a[j];
			sum+=a[j];
			j--;
			k=1;
		}
		if((k==0)&&(a[j]>a[f])&&(c[j]!=c[f])){
			a[j]-=a[f];
			sum+=a[f];
			f++;
			k=1;
		} 
		if((k==0)&&(a[j]==a[f])&&(c[j]!=c[f])){
			f++;
			j--;
			sum+=a[f-1];
			k=1;
		}
		if(k==0){
			f++;
			j--;
			e+=a[f-1];
			sum+=a[f-1];
		}
		if(sum>=(d/2)){
			break;
		}
	}
	cout<<(sum-e);
}
