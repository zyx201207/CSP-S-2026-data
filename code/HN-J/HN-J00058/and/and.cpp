#include<bits/stdc++.h>
#define N 10005
using namespace std;
string bin(int a){
	string s;
	while(a){
		s+=char(a%2+48);
		a/=2;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int t=n;
	long a[N];
	int hash[N]={-1};
	int max=0; 
	while(t--){
		cin>>a[n-t];
		if(max <= a[n-t]) max=a[n-t]; 
	}//a[i]:Êý¾Ý 
	vector<string> bina(n);
	for(int i=0;i<n;i++){
		bina.push_back( bin(a[i]) );
	}//transform
	
	//shape length
	int maxl=bin(max).length();
	for(int i=0;i<n;i++){
		int delta=maxl-bina[i].length();
		while(delta--) bina[i]="0"+bina[i];
	}
	t=0;
	bool flag=0;//not found yet
	int cnt1=0;
	while(t<maxl){
		if(cnt1 = m) break;
		for(int i=0;i<n;i++){
			if(bina[i][t] == 1 && cnt1<m ) {
				cnt1++;
				hash[i]=1;
			}
			if(bina[i][t] == 0 && cnt1>m ) {
				cnt1++;
				hash[i]=0;
			}
		}
		
		t++;
	}
	int and=max;
	for(int i=0;i<n;i++){
		if(hash[i] == 1) and &= a[i];
	}
	
	cout<<and;
	return 0;
}
