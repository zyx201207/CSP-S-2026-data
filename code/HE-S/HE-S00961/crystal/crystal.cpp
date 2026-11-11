#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	long long m;
	cin>>n>>m;
	long long a[n+1];
	long long b[n+1];
	unsigned long long c[n+1];memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//cout<<a[i]<<" ";
		b[i]=a[i];
		c[i]=a[i]+c[i-1];
	}
	//cout<<endl;
	long long sum=0;
	for(int i=1;i<=n;i++){
		long long s=0;
		b[i]+=m;
		for(int j=1;j<=n;j++){
			if(b[i]==b[j] && i!=j){
				s++;	
			}
			//cout<<b[j]<<" ";
		}
		//cout<<endl;
		if(s>=sum){
			sum=s;
		}
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}			
	}
//	for(int j=1;j<=n;j++){
//			cout<<c[j]<<" ";
//		}
//		cout<<endl;
	//i m-i m-i-i1 m-i-i1-i2 m-i-i1-i2-i3;
//	for(int i=1;i<=n;i++){
//		int m1=m-1,m2=1;
//		cout<<m1<<endl;
//		for(int i1=1;i1<=n;i++){
//			if(i==i1){
//				continue;
//			}	
//			if(m1<m2){
//				break;
//			}		
//			int s=0;
//			b[i]+=m1;
//			b[i1]+=m2;
//			cout<<b[i]<<" "<<b[i1]<<endl;
//			if(b[i]==b[i1]){
//				s++;	
//			}
//			if(s>=sum){
//				sum=s;
//			}
//			for(int j=1;j<=n;j++){
//				b[j]=a[j];
//			}	
//			m1--;
//			m2++;	
//		}	
//	}
	for(int i=1;i<=n;i++){
		long long s=0;
		if(c[i]+m==a[i]*i){
			s=i;
		}
		if(s>=sum){
			sum=s;
		}
	}
	cout<<sum;
	return 0;
}
