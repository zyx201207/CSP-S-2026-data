#include<bits/stdc++.h>
using namespace std;
int cha[5];
int shu[5];
int main(){
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>shu[i];
	}
	if(m==0){
		cout<<0;
		return 0;
	}
	int q=shu[1]-shu[0];
	for(int i=1;i<n;++i){
		if((shu[i]-shu[i-1])<=q){
			q=shu[i]-shu[i-1];
			cha[i-1]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(cha[i]==1){
			shu[i]+=q;
			m-=q;
		}
	}
	cout<<m<<endl;
	return 0;
}
