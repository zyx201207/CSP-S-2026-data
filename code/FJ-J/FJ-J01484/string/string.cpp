#include<bits/stdc++.h>
using namespace std;
char e[1000000001];
long long cnt=1;
long long n;
long long l,r,num=0;
long long sa;
char sas;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1;
	
	for(int i=1;i<=n;i++){
		cin>>sa>>sas;
		for(int j=1;j<=sa;j++){
			e[cnt++]=sas;
		}
	}
	cnt--;
	r=cnt;
	while(l<=r){
		if(e[l]!=e[r]){
			e[r]=e[l];
			//cout<<l<<" "<<r<<endl;
			num++;
		}
		l++;
		r--;
	}
	cout<<num;
	return 0;
}
