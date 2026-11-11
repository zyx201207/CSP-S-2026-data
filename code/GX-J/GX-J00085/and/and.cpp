#include <bits/stdc++.h>
using namespace std;
int m,n,x;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	vector<int> y;
	vector<int> c;
	vector<int> sy;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>x;
		c.push_back(x);
	}
	for(int j=0;j<(int)c.size();j++){ 
		y.push_back(c[j]%2);
		sy.push_back(c[j]%2);
		cout<<y[j]<<"  ";
	}
	cout<<"12";
	return 0;
}
