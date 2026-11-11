#include<bits/stdc++.h>
using namespace std;
stack<long long> aa;
long long a[200005]={},b[300005]={},n,m,c[300005][2]={},ans=0;
long long cs(){
	for(long long j=0;j<n;j++){
		for(long long i=j;i<n;i++){
			aa.push(a[i]);
			c[a[i]][0]++;
			if(c[a[i]][0]==2){
				c[a[i]][0]--;aa.pop();
				while(aa.top()!=a[i]){
					c[aa.top()][0]--;aa.pop();
				}
			}
		}
		while(!aa.empty()){
			c[aa.top()][0]--;c[aa.top()][1]++;aa.pop();
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long f=0;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(b[a[i]]!=0) f=1;
		b[a[i]]++;
	}
	if(f==0){
		for(long long i=0;i<n;i++) c[a[i]][0]+=i+1;
		for(long long i=1;i<m+1;i++) cout<<c[i][0]<<" ";
		return 0;
	}
	if(m==1){
		cout<<n;return 0;
	}
	cs();
	for(long long i=1;i<m+1;i++) cout<<c[i][1]<<" ";
	
	
	return 0;
}

