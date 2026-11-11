#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	long long m,n;
	cin>>m>>n;
	long long a[10000];
	for(long long i=0;i<m;i++){
		cin>>a[i];
	}
	
	for(long long i=0;i<m;i++){
		for(long long j=i;j<m;j++){
			if(a[i]>a[j]){
				long long p=a[j];
				a[j]=a[i];
				a[i]=p;
			}
		}
	}
	

	long long b[m];
	for(long long i=0;i<m;i++){
		b[i]=0;
	}
	
	
	for(long long i=0;i<m;i++){	
	long long s=0;
		for(long long j=i;j<m-1;j++){
			s+=a[j];
			if(!(abs((s+n)/n)<(j-1))){
				b[i]=j;
				break;
			}
		}
	}
	
	for(long long i=0;i<m;i++){
		for(long long j=i;j<m;j++){
			if(b[i]<b[j]){
				long long p=b[j];
				b[j]=b[i];
				b[i]=p;
			}
		}
	}
	
	cout<<b[0];
	
	fclose(stdin);
	fclose(stdout);
return 0;}
