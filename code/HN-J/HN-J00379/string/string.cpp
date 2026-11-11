#include<bits/stdc++.h>
using namespace std;
int n;
int m;
char b;
int l;
int h;
long long ans;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>b;
		for(int j=0;j<m;j++){
			a[l]=b;
			l++;
		}
	}
	h=l/2;
	if(h%1!=0) h-0.5;
	for(long long i=0;i<h;i++){
		if(a[i]!=a[l-i-1]) ans+=1;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

