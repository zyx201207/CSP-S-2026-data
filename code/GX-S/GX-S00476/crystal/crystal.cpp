#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,a[500003],t[500003][2],ans=0;
int main(){
	fstream fin,fout;
	fin.open("crystal.in");
	fout.open("crystal.out");
	fin>>n>>m;
	for(int i=0;i<n;i++){
		fin>>a[i];
	}
	sort(a,a+n);
	long long j=n-1,t1=0;
	for(long long i=n-1;i>=0;i--){
		for(;;){
			if(j>=0)j--;
			if(t1+a[i]-a[j]<=m)t1+=a[i]-a[j];
			else break;
			if(j<0)break;
		}
		t[i][0]=t1;
		t[i][1]=j;
		ans=max(ans,i-j);
		t1-=(a[i]-a[i-1])*(i-j);
		if(t1<0)t1=0;
		j++;
	}
	fout<<ans;
	return 0;
}
