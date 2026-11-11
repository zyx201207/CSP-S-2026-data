#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string as="";
	long long sa=0;
	int aa;
	char cc;
	for(int i=1;i<=n;i++){
		scanf(" %d %c",&aa,&cc);
		sa+=aa;
		for(int j=1;j<=aa;j++){
			as+=cc;
		}
	}
	long long l=0,r=sa-1;
	long long a=0;
	while(l<r){
		if(as[l]!=as[r]){
			a++;
		}
		l++;
		r--;
	}
	cout<<a;
	return 0;
}
