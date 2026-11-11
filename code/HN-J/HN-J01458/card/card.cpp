#include<bits/stdc++.h>
using namespace std;
int a[100002];
int b[100002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,c;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=0;i<n;i++)b[i]=a[i];
	for(int i=0;i<n;i++)
	{
		int num=0;
		for(int j=c-1;j!=i;j++){
			if(a[j]==a[i]){
			cout<<num;
			c=i;
			continue; 
			} 
			num++;
		}
	}
	return 0;
} 
