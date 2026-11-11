#include<bits/stdc++.h>
using namespace std;
int main(){
	//GZ-J00036,贵州省贵阳市南明区第一实验中学，罗圣杰 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,cnt=0;
	string x,y,z;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>x;
		for(int j=0;j<a;j++){
			y+=x;
		}
	}
	bool q[y.size()];
	for(long long l=y.size();l>-1;l--){
		z+=y[l];
	}
	for(long long k=0;k<y.size();k++){
		if(y[k]!=z[k]){
			cnt++;
		}
	}
	cout<<(cnt+1)/2;
	return 0;
}
