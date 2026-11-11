#include<bits/stdc++.h>
using namespace std;
int n;
struct ad{
	int s;
	string z;
};
int cnt;
ad a[200005];
string ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].z;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].s;j++){
			ss+=a[i].z;
		}
	}
	int sss=ss.size()-1;
	string x;
	for(int i=sss;i>=1;i--){
		x[i]=ss[i];
	}
	for(int i=1;i<=sss;i++){
		if(x[i]==ss[i]){
			cnt++;
		}
	}
	if(cnt==sss-1){
		cout<<0<<endl;
		return 0;
	}
	cnt==0;
	string y,z;
	int s1=sss/2;
	for(int i=1;i<=s1;i++){
		y[i]==ss[i];
	}
	for(int i=sss;i>=s1;i--){
		z[i]=ss[i];
	}
	for(int i=1;i<=s1;i++){
		if(y[i]==z[i]){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
