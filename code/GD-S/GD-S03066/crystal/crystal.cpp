#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500001]={},sum=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		while(a[i]<=a[i+1]){
			m--;
			a[i]+=1;
			if(m==0) break; 
		}
		sum++;
		if(m==0) break;
	} 
	cout<<sum;
	return 0;
}
