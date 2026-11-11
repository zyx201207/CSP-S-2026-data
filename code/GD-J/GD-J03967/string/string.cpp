#include<bits/stdc++.h>
using namespace std;
struct data{
	char words;
	int count;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,count=0,sum=0;
	cin>>n;
	int an,q;
	data ac[n];
	for(int i=0;i<n;i++){
		cin>>ac[i].count;
		cin>>ac[i].words;
		an+=ac[i].count;
	}
	char x[an];
	for(int i=0;i<n;i++){
		for(int j=0;j<ac[i].count;j++){
			x[sum]=ac[i].words;
			sum++;
		}
	}
	for(int i=0;i*i<sum;i++){
		if(x[i]!=x[sum-i-1]){
			count++;
		}
	}
	cout<<count;
	return 0;
}
