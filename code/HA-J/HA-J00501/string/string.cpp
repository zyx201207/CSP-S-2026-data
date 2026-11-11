#include<bits/stdc++.h>
using namespace std;
int a[200005];
string y[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int p;
	cin>>p;
	
	string a;
	for(int i=1;i<=p;i++){
		int temp;
		cin>>temp;
		char temp1;
		cin>>temp1;
		while(temp--){
			a+=temp1;
		}
	}
	int len=a.size();
	string x,y;
	if(len%2==0){
		x=a.substr(0,len/2);
		y=a.substr(len/2+1);
	}
	if(len%2==1){
		x=a.substr(0,len/2+1);
		y=a.substr(len/2);
	}
	int sum=0;
	reverse(x.begin(),x.end());
	for(int i=0;i<x.size();i++){
		if(x[i]!=y[i])sum++;
	}
	cout<<sum;
	
	return 0;
} 
