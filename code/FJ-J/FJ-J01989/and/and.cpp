#include<bits/stdc++.h>
using namespace std;
string s[200005]; 
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]){
			if(a[i]%2==1)s[i]='1'+s[i];
			else s[i]='0'+s[i];
			a[i]/=2;
			//cout<<1;
		}
		for(int j=30-s[i].size();j>=1;j--)s[i]='0'+s[i];
		//cout<<s[i]<<" ";
	}
	long long sum=0;
	for(int i=0;i<=29;i++){
		int cnt=0,flag=0;
		for(int j=1;j<=n;j++){
			if(s[j][i]=='1')cnt++;
		}
		if(cnt>=m)sum+=pow(2,30-i-1),flag=1;
		if(flag==1){
			for(int j=1;j<=n;j++){
				if(s[j][i]!='1')s[j]="000000000000000000000000000000";
			}
		}
	}
	cout<<sum;
	return 0;
} 
