#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,m1;
	cin>>n>>m;
	m1=m;
	for(int i=0;i<n;i++){
		int a_in;
		cin>>a_in;
		a.push_back(a_in);
	}
	sort(a.begin(),a.end());
	int b=0;
	for(int i=1;i<=n;i++){
		int c=0;
		for(int j=1;j<=n;j++){
			if(a[i]+1==a[i+1]&&m1>0){
				c++;
				m1--;
			}
		}
		if(c>b) b=c;
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
