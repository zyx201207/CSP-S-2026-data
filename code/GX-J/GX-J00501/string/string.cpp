#include <bits/stdc++.h>
using namespace std;
const long long N=1e9+5;
struct aaa{
	long long num;
	char zimu;
};
aaa a[N];
string v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].zimu;
		for(long long j=0;j<a[i].num;j++){
			v+=a[i].zimu;
		}
	}
	long long l=0,r=v.size()-1,numer=0;
	while(l<r){
		if(v[l]!=v[r]) numer+=1;
		l++;
		r--;
	}
	cout<<numer;
	return 0;
}
