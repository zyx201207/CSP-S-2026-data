#include<bits/stdc++.h>
using namespace std;
const int N =5e5+5;
int a[N];

int main(){
	int sub=0;
	//freopen("crystal","r",stdin);
	//freopen("crystal","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int sum=0;
	int total=0;
	int now=0;
	for(int i=1;i<n;i++){
	for(int j=1;j<n;j++){
	//	if(a[i]-a[i-j]);
	sum=sum+a[i]-a[i-j];		
		if(sum>n){
	//	break;
	total=i;
	now=a[i-j];
		}
//	sub=sum; 	
	}
	}
	sub=total;
	for(int i=total; ;i++){
		if(a[i]==now){
			sub++;
		}
		else
		break;
	}
	cout <<sub;
	return 0;
} 
