#include<bits/stdc++.h>
typedef int ll;
using namespace std;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	ifstream fin("and.in");
	ofstream fout("and.out");
	ll n,m;
	fin>>n>>m;
	ll a[n];
	ll fla[n]={false};
	for(ll i=0;i<n;i++){
		fin>>a[i];
	}
	sort(a,a+n,cmp);
	ll sum=a[0];
	for(int i=1;i<m;i++){
		ll max1=0;
		ll bj=0;
		for(int j=0;j<n;j++){
			if(sum&a[j]>max1&&!fla[j]){
				max1=sum&a[j];
				bj=j;
			}
		}
		sum=max1;
		fla[bj]=true;
	}
	fout<<sum;
	fin.close();
	fout.close();
	return 0;
} 
