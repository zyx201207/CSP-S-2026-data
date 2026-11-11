#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=0,num=0;//s求平均数 ,num计数 
	cin>>n>>m;
	long long a[n];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<=m;j++){
			if(a[i]<s/n){
				a[i]++;
				m--;
			}
			if(a[i]==s/n){
				num++;
			}	
		}
		
	}
	
	//for(int i=1;i<=n;i++){
	//	cout<<a[i]<<" ";
	//}
	cout<<num;//<<" "<<m<<" "<<s;
}




























