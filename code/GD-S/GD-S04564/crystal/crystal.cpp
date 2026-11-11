#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500001];
long long sum=1;
long long max1=0;
long long many=0;
bool db=true;
int main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int org=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]&&i>1) db=false;
	}
	if(db){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int qd=1;qd<n;qd++){
		sum=1;
		m=org;
		//cout<<"qdnum:"<<a[qd]<<endl;
		for(int i=qd+1;i<=n;i++){	
			m-=(a[i]-a[i-1])*((i-qd+1)-1);
			if(m>=0){
				sum++;
				//cout<<"nownum:"<<a[i]<<endl;
			}
			else{
				break; 
			}
		}
		max1=max(max1,sum);
	}
	cout<<max1;
	return 0;
} 
