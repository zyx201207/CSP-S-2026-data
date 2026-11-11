//GZ-J00459 凤冈县第四中学 李朋秦 
#include<bits/stdc++.h>
using namespace std;
long long n,a,x=0;
string c,z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		for(long long j=0;j<a;j++)z+=c;
	}
	int f=z.size();
	for(int i=0;i<=f/2-1;i++){
		if(z[i]!=z[f-i-1]){
		x++;
		}
	}
	cout<<x;
	return 0;
}
