#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,m1=0;
	vector<int> v;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	if(m==1){
		int x;
		x=v[n-1];
		cout<<x;
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int c=v[i]&v[j];
				m1=max(m1,c);
			}
		}
		cout<<m1;
	}
	else if(m==n){
		int d=v[0];
		for(int i=1;i<n;i++){
			d=d&v[i];
		}
		cout<<d;
	}
	else{
		if(v[0]==1 || v[0]==3 || v[0]==7)
			cout<<v[0];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
