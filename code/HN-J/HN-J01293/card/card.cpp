#include<bits/stdc++.h>
using namespace std;
long long int a[1000000],b[10000000];
int main(){
	long long int i,n,m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
	cin>>a[i];
	b[a[i]]++;	
	} 
	for(i=0;i<n;i++){
		if(b[a[i]]!=0){
		cout<<b[a[i]]<<" ";
		b[a[i]]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
