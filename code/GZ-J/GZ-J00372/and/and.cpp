//GZ_J00372 杨荣睿 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;

long long n,m,a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	cin>>n>>m;
	vector<int>v;
	for(int i=0;i<n;i++){
	    cin>>a;
	    v.push_back(a);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	cout<<v[1];
	return 0;
} 
