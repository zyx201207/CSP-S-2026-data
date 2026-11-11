#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,a[N],len=0,sum=0;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;char c;
		cin>>num>>c;
		a[i]=num;b[i]=c;
		len+=num;
	}
	long long t=0,c=0,j=n;
	for(int i=1;t<len/2;i++){
		if(t+a[i]>len/2){
			c=len/2-t;
			t=len/2;
		}else{
			t+=a[i];c=a[i];
		}
		while(c){
			if(a[j]<=c){
				c-=a[j];
				if(b[j]!=b[i])sum+=a[j];
				j--;
			}else{
				a[j]-=c;
				if(b[j]!=b[i])sum+=c;
				c=0;
			}
		}
	}
	cout<<sum;
	return 0;
} 
