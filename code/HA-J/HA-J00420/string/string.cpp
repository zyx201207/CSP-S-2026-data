#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,j=0;
	cin>>n;
	int a[n+2];
	string c[n+2],s,x,y;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}	
	}
	for(int i=0;i<n;i++){
		if(c[i]==c[i+1]){
			cnt++;
		}
		if(cnt+1==n){
			cout<<"0";
			return 0;
		}
	}
	cnt=s.size()/2;
	while(j<cnt){
		for(int i=s.size()-1;i>cnt-1;i--){
		y[j]=s[i];
		j++;
	}
	}
	int sum=0;
	for(int i=0;i<cnt;i++){
		if(s[i]!=y[i]) sum++;
	}
	cout<<sum;
	return 0;
}
