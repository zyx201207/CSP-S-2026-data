#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e5+5;
int a[N];
char c[N],b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num=1,cnt=1,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b[num]=c[i];
			num++;
		}
	}
	num=0;
	for(int i=1;i<=n;i++){
		num+=a[i];
	}
	for(int i=num;i>float(num/2);i--){
		if(b[i]!=b[cnt]){
			sum++;
		}
		cnt++;
	}
	cout<<sum;
	return 0;
}

