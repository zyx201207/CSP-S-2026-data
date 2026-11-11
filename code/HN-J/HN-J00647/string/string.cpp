#include<bits/stdc++.h>
using namespace std;
const int N=1E8+5;
int a[N];
char c[N];
string s;
int whs(string n){
	int sum=0;
	int l=0;
	int len=n.size();
	int r=len-1;
	if(len==1) return 0;
	while(l!=r){
		if(n[l]==n[r]){
			l++;
			r--;
		}else{
			sum++;
			l++;
			r--;	
		}
	}
	return sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	cout<<whs(s);
	return 0;
}
