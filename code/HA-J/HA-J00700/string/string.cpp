#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long len=0;
long long c[28];
long long topo[100005]={0};
char js[100005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for(int i =1; i<=n; i++){
		int x;
		char y;
		cin>>x>>y;
		len+=x;
		//c[y-'a'+1] += x;
		topo[i] = x;
		js[i] = y;
		//for(int j = 1; j<=x; j++){
		//	js[len+j] = y;
		//}
		len+=x;
	}
	long long p = 0;
	//for(int i = 1; i<=len/2 ; i++){
	//	if(js[i] != js[len-i+1]){
	//		p++;
	//	}
	//}
	long long l=1, r=n;
	while(l < r){
		if(js[l] ==js[r]){
			long long s = min(topo[l],topo[r]);
			topo[l] -= s;
			topo[r] -= s;
		}else{
			long long s = min(topo[l],topo[r]);
			topo[l] -= s;
			topo[r] -= s;
			p+=s;
		}
		if(topo[l] == 0){
			l++;
		}
		if(topo[r] == 0){
			r--;
		}
		//cout<<1;
	}
	cout<<p;
	return 0;
}
