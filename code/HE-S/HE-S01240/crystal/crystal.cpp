#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m,c,zhong=0,o=0,e=0;
	cin>>n>>m;
	int s[n];
	int xiao[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(s[i]>s[j]){
				c=s[i];
				s[i]=s[j];
				s[j]=c;
			}
		}
}
	if(n%2==0){
		zhong=s[n/2-1];
	}
	else{
		zhong=s[n/2];
	}
	for(int i=0;i<n;i++){
		if(s[i]<=zhong){
			e++;
		}
	}
	cout<<e;
	return 0;
 } 
