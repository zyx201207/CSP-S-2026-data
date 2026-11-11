#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
string ss,s;
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++){
	cin>>a[i]>>ss[i];
	sum+=a[i];
	}
		for(int j=0;j<sum/2;j++){
			if(a[j]!=a[n-j]){
				cnt++;
			}
		}
	cout<<cnt<<endl;
	return 0;
} 
