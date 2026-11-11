#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	char c[n];
	int x=0;
	vector<char> v;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			v.push_back(c[i]);
		}
	}
	int res=0;
	int d=(v.size()-1)/2;
	for(int i=0;i<=d;i++){
	    if(v[i]!=v[v.size()-1-i]) res++;
	}
	cout<<res;
	return 0;
}