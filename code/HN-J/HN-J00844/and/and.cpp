#include<bits/stdc++.h>
using namespace std;
int n,m;
vector <int> a;
void b(int c){
	vector <int> w;
	string s;
	while(c!=0){
		int d=c%2;
		w.push_back(d);
		c/=2;
	}
	for(int i=w.size()-1;i>=0;i++){
		s+=w[i];
	}
	cout<<s;
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		a.push_back(0);
		cin>>a[i];
	}
	if(n==m){
		int z=a[0]&a[1];
		for(int i=2;i<m-1;i++){
			z=z&a[i];
		}
		cout<<z&a[m-1]; 
	}else if(m==1||n==1){
		int z=a[0];
		for(int i=1;i<n;i++){
			z=max(z,a[i]);
		}
		cout<<b(z);
	}
	return 0;
} 
