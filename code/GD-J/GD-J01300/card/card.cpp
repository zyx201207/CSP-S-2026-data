#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector<int> k;
vector<int> l;
int e=0;
int sum;
void f(int y){
	if(y==m){
	sum=k[0];
		for(int i=0;i<k.size()-1;i++){
			sum=sum&k[i];
		}
	}
	else{
		sum=k[0];
		sort(k.begin(),k.end());
		for(int i=0;i<m-1;i++){
			sum=sum&k[i];
		}
	}
	return ;
}
void check(int t){
	int r=0; 
	for(int i=0;i<n;i++){
		if(l[i]==t){
			r++;
		}
	}
	if(r>=m){
		for(int i=0;i<n;i++){
		if(l[i]!=t){
			k.erase(l.begin()+i);
		}
	}
	f(t);
	return;
	}
	if(r<m){
		check(e-1);
	}
}

int main(){

	cin>>n>>m;
	
	vector<int> a;
	
	for(int i=0;i<n;i++){
		int b;
		cin>>b;
		int c=0;
		int q=0;
		while(b!=0){
		b=b/2+b%2;
		k.push_back(b%2);
		q++;
	}
	l.push_back(q);
	if(e<q){
		e=q;
	}
		if(q<b){
			q=b;
		}
		a.push_back(b);
	}
	check(e);
	cout<<sum;
}


