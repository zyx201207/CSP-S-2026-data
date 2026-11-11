#include<bits/stdc++.h>
using namespace std;
int x[1234567];
long long y[1234567];
char a[1234567],b[12345678];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,j=0;
	long long sum=0,h;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>a[i];
		sum+=x[i];
		y[i]=sum;
		for(int j=1;j<=x[i];j++){
			b[sum-x[i]+j]=a[i];
		}
	}
	h=sum/2;
	if(sum%2==0){
		for(int i=1;i<=h;i++){			
			if(b[i]!=b[sum-i+1]){
				++cnt;
			//	cout<<b[i]<<" "<<b[i+h+1];
				
			}
		}
	}else{
		for(int i=1;i<=h;i++){			
			if(b[i]!=b[sum-i+1]){
				++cnt;	
				
			}	
		}
	}
	cout<<cnt;
	return 0;
}

