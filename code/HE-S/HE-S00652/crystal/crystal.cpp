#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int n,m;
int nl[50001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long average;
	for(int i=0;i<n;i++){
		cin>>nl[i];
		average+=nl[i];
	}
	average = average / n;
	sort(nl,nl+n);
	long long ans = 0;
	for(int i=0;i<n;i++){
		if(nl[i]>average){
			nl[i] = 0;
		}
	}
	for(int i=n;i>0;i--){
		if(nl[i]<=m){
			m-=nl[i];
			ans++;
		}
	}
	cout<<ans+1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
