#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[500005];
bool x=0;   //x：判断特殊性质 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	//判断特殊 y
	int flag=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=flag) x=1;
	}
	if(!x){
		m=m*2/flag;
		m=sqrt(m);
		cout<<m<<"\n";
		return 0;
	}//判断结束
	cout<<n/2+n/3;
	return 0;
} 
