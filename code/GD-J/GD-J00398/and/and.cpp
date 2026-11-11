#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	long long a[n+5];
	long long y=0,y2=0,c=0,c2=0;
	long long m1=-1;
	long long m2=-1;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		a[i]=x;
		while(x>1){
			int x2=x%2;
			if(x2==1){
				y++;
			}
			x/=2;
		}
		
		if(m<y){
			c=i;
		}
		m1=max(y,m1);
		
		x=a[i-1];
		while(x>1){
			int x2=x%2;
			if(x2==1){
				y2++;
			}
			x/=2;
		}
		if(max(y2,m2)<m1){
			m2=max(y2,m2);
			c2=i-1;
		}
	}
	long long t=a[c],t2=a[c2];
	long long m3=max(t,t2),mi=min(t,t2);
	int sum=0;
	int i=0;
	while(m3>1 || mi>1){
		int x2=m3%2,x3=mi%2;
		int s=(x2&x3);
		sum+=s*pow(2,i);
		i++;
		m3/=2;
		mi/=2;
	}
	cout<<sum;
	
	
	
	
	return 0;
}
