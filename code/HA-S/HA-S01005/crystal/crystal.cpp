#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	long long n,m;
	long long num=1,x=0,d=0;
	cin>>n>>m;
	int a[n];
	if(d<=n){
		d++;
		cin>>a[d+1];
	}else{
		d++;
	}
	int s[n-1];
	while(x<=n-1){
		if(a[n-x-1]>a[n-x]){
			s[n-x-1]=a[n-x-1]-a[n-x];
			x++;
		}else{
			s[n-x-1]=a[n-x]-a[n-x-1];
			x++;
		}
		if(s[n-x-1]<s[n-x]){
			a[n-x-1]=a[n-x-1]+1;
			m=m-1;
		}else{
			num=num+1;
		}
		if(m=0){
			break;
		}
	}

	cout<<num<<endl;
	return 0;
}



		
		
		
		
		
