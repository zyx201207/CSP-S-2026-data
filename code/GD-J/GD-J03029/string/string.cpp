#include<bits/stdc++.h>
using namespace std;
string s;
int a[200000];
char b[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	int l=0,r=n-1;
	while(r>=l){
		int mini;
		if(a[l]>=a[r])mini=r;
		else mini=l;
		if(b[l]!=b[r])ans+=a[mini];
		a[l]-=a[mini];
		a[r]-=a[mini];
		if(mini==l)l++;
		else r--;		
	}
	cout<<ans;
	return 0;
} 
