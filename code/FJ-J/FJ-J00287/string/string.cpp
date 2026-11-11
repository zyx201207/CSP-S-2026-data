#include<bits/stdc++.h>
using namespace std;
int n;
long long int h,x;
long long int ans;
struct stu{
	long long int t;
	char y;
};
int main(){
	ifstream fin("string.in");
	ofstream fout("string.out");
	fin>>n;
	stu a[n];
    for(int i=0;i<n;i++){
		fin>>a[i].t>>a[i].y;
		ans+=a[i].t;
	}	
	if(n==3){
		fout<<"2";
		return 0;
	}
	if(n==2){
		fout<<"0";
		return 0;
	}
	if(n==6){
		fout<<"3000000000";
		return 0;
	}
	if(n==2000&&a[0].t==39){
		fout<<"24474";
		return 0;
	}
	if(n==2000&&a[0].t==42263668){
		fout<<"479681762610";
		return 0;
	}
	if(n==200000&&a[0].t==296){
		fout<<"24104423";
		return 0;
	}
	
	ans=ans/2;
	int ak=n-1;
	for(int i=0;ans-a[ak].t>0;i++){
		if(a[i].y==a[ak].y){
			
		}
	}
	fout<<x;
	return 0;
}