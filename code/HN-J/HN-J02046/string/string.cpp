#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long sum=0,x=0;
	string s[10005];
	cin>>n;
	for(int i=1;i<=n;i++){
		long long m;
		string A;
		cin>>m>>A;
		for(int j=x+1;j<=m;j++){
			s[j]=A;
		}
		x+=m;
	}
	long long y=(x+1)/2;
	for(int i=1;i<=y-1;i++){
		if(s[y-i]!=s[y+i]){
			sum++;
		}else{
			sum+=0;
		} 
	}
	cout<<sum;
	return 0;
}
