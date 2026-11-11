#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100000005];
string b[10005];
long long sum;
int ans=1;
string q;
int main(){ 
//	freopen("in.string","r",stdin);
//	freopen("out.string","w",stdout);
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;	
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		q=b[i-1];
		if(b[i]!=q){
			ans=0;
		}
		sum+=a[i]; 
	}
	if(ans==0){
		sum=sum/2;
		cout<<sum;
	}
	else{
		cout<<"0";	
	}
	return 0;
}
