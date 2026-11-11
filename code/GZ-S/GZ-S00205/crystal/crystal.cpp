//GZ-S00205 遵义市新浦新区滨湖中学  王辰睿 
#include<bits/stdc++.h>
using namespace std;

int main(){
	ifstream fin("crystal.in");
	ofstream fout("crystal.out.ans");
	long long n,m,sum=1;
	long long a[199999];
	fin>>n>>m;
	for(long long i=0;i<n;i++){
		fin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long z=i;z<n;z++){
			if(a[i]>a[z]){
				long empt=a[i];
				a[i]=a[z];
				a[z]=empt;
			}
		}
	}
	long long j=0;
	while(m>0){
		m-=abs(a[j+1]-a[j]);
		if(m<0) break; 
		j++;
		sum++;
	}
	fout<<sum;
	return 0;
}
