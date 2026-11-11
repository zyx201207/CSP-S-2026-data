#include<bits/stdc++.h>
using namespace std;
char d[200000000];
int b[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long num=0,f=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i]>>c[i];
		for(int j=0;j<b[i];j++){
			d[num]=c[i];
			num++;
		}
	}
	for(int i=0;i<num/2;i++){
		if(d[i]!=d[num-i]){
			f++;
		}
	}
	cout<<f;
	return 0;
}
