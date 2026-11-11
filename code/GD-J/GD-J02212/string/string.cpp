#include<bits/stdc++.h>
using namespace std;
const int N=10;
char a[N];
int num[N];
long long n,sum=0;
void f(int x1,int x2,int k1,int k2){
	if(x1>=x2)return ;
	if(num[x1]-k1>=num[x2]-k2){
		if(a[x1]!=a[x2])sum+=num[x2]-k2;
		k1+=num[x2]-k2;
		x2--;
		k2=0;
	}
	else {
		if(a[x1]!=a[x2])sum+=num[x1]-k1;
		k2+=num[x1]-k1;
		x1++;
		k1=0;
	}
	f(x1,x2,k1,k2);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>num[i]>>a[i];
	f(0,n-1,0,0);
	cout<<sum;
	return 0;
}
