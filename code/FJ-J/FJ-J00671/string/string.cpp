#include<bits/stdc++.h>
using namespace std;
int x[22225];
int a[22225];
char c[22225];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n,m,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	m=s.size();
	for(int i=0;i<m;i++){
		if(x[i]!=0&&x[m+1-i]!=0){
			if(s[i]!=s[m+1-i]){			
				sum++;
			}
		}
		x[i]=1;
		x[m+1-i]=1;
	}
	cout<<sum;
	return 0;
}

