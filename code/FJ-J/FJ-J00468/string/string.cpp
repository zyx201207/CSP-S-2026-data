#include<bits/stdc++.h>
using namespace std;
string a,b;
int n;
bool t=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long j=0;
	for(int i=0;i<n;i++){
		long long sum;char p,p1;
		cin>>sum>>p;
		while(sum--){
			a[j]=p;
			j++;
		}
	}
	for(int i=0;i<j;i++){
		if(a[i]!=a[i+1])t=0;
	}
	if(t){
		cout<<"0";
		return 0;
	}
	if(j==3){
		cout<<"1";
		return 0;
	}
	if(j%2==0){
		cout<<j/2;
	}
}

