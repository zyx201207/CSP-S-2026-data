#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0;
	long long a[1000],d=0,f=0;
	char b[1000];
	bool t=0;
	string c,e;
	cin>>n;
	if(n<1){
		return 0; 
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		if(i>0){
			if(b[i]==b[i-1]){
				t=1;
			}
		}
		d+=a[i];
	}
	if(n==2){
		if(b[0]==b[1]){
			cout<<0;
		}
		else if(d%2==0){
			cout<<d/2;
		}
		else{
			cout<<d/2+1;
		}
	}

	if(t==1){
		cout<<0;
	}
	return 0;
}

 
