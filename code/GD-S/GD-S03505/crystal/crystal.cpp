#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[500005];
	for(int i=0;i<n;i++)cin>>s[i];
	sort(s,s+n);
//	for(int i=0;i<n;i++)cout<<s[i]<<" ";
 
	int x=0,q=0;
	while(q!=m){
		if(s[x]<s[x+1]){
		//	q++;
			s[x]++;
		}
		else x++;
		q++;
	}
	cout<<x+1;
	return 0;
} 
