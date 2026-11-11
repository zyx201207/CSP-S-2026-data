#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,mm=0,nn=0;
	long long s;
	cin>>n>>m;
	vector<long long> a;
	for(int i=0;i<n;i++){
		cin>>s;
		a.push_back(s);
	}
	for(int i=0;i<n-1;i++){
		nn=0
		for(int j=i;j<n;j++){
			if(a[j]+1==a[i]){
				nn++;
			}
		}
		mm=max(mm,nn);
	}
	if(mm>m){
		cout<<m<<endl;
	}
	else{
		cout<<mm<<endl;
	}
	return 0;
}
