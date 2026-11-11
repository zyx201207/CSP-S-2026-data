#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	int m=n;
	int x[10005];
	string y[10005];
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if(n==1){
		cout<<"0";
		return 0;
		}
		while(m>1){
			sum+=x[i]/2;
			m--;
		}
	}
	cout<<sum;
	return 0;
}

