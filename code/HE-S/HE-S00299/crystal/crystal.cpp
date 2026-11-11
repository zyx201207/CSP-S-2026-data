#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long sum=0;
	cin>>n>>m;
	long long t=n+20;
	long long a[t];
	long long mi=1000000000,w=0,v=0;
	int c=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m+1;i++){
		m-=i;
		if(m<0){
			break;
		}
		cout<<m<<" ";
		sum++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
