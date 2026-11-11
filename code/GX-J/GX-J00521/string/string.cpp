#include<bits/stdc++.h>
using namespace std;
int need;
long long n,sum,sum1;
char b;
string a,newa;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>need;
	for(int i=0;i<need;i++){
		cin>>n;
		cin>>b;
		sum+=n;
		for(int j=1;j<=n;j++){
			a+=b;
		}
	}
	if(sum%2==0){
		for(int i=sum/2;i<sum;i++){
			newa+=a[i];
		}
		for(int i=0;i<sum/2-1;i++){
			if(newa[i]!=a[sum/2-i-1]){
				sum1+=2;
			}
		}
	}else{
		for(int i=sum/2+1;i<sum;i++){
			newa+=a[i];
		}
		for(int i=0;i<sum/2-1;i++){
			if(newa[i]!=a[sum/2-i-1]){
				sum1+=2;
			}
		}
	}
	cout<<sum1;
	return 0;
}

