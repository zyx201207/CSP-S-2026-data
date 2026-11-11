#include<bits/stdc++.h>
using namespace std;
int n,sum,m;
int s[200005];
int main(){
	freopen("and2.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int u=1;u<n-1;u++){
		for(int i=1;i<n-1;i++){
			if((s[i-1] & s[i])<(s[i] & s[i+1])){
				int j=s[i-1];
				s[i-1]=s[i+1];
				s[i+1]=j;
			}
		}
	}
	sum=s[0];
	for(int i=1;i<m;i++)sum&=s[i]; 
	cout<<sum;
	return 0;
}
