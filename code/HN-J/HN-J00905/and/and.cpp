#include<bits/stdc++.h>
using namespace std;
vector<int> c;
string d,l;
int a[100000],b[100000]; 	
int n,o;
string ap(int x){
	string q;
	while(x<2){
		q+=x%2+'0';
		x/2;
	}
	if(x==1){
		q+='1';
	}
	return q;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>o;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int j=0;
	for(int i=n-1;i>=0;i--){
		b[j]=a[i];
		j++;
	}
	for(int i=0;i<o;i++){
		c[i]=b[i];
	}
	for(int i=0;i<c.size();i++){
		int x=c[i];
		d[i]=ap(x);
	}
	for(int i=0;i<d.size();i++){
		l+=d[i];
	}
	cout<<l;
}

