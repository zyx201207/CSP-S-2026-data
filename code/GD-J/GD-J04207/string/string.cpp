#include<bits/stdc++.h>
using namespace std;
long long n,sum[100000000],si,num;
char a[100000000];
string v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>sum[i]>>a[i];
		for(int j=1;j<=sum[i];j++){
			v+=a[i];
		}
	}
	si=v.size();
    for(int i=0;i<si;i++){
    	if(v[i]!=v[si-i-1]){
    		num++;
		}
	}
	if(si%2==0){
		num/=2;
	}
	cout<<num;
}
