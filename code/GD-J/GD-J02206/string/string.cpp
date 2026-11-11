#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long a[N];
char c[N];
bool st=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i!=1&&c[i]!=c[i-1]) st=false;
	}
	if(st){
		cout<<0;
		return 0;
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	cout<<sum/2;
	return 0;
}
