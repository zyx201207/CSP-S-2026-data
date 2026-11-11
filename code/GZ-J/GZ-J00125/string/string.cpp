//GZ-J00125 习水县第七中学 李卓巾 

#include <bits/stdc++.h>
using namespace std;

long long n,a[100000],sum=0;
char c[100000];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string x=" ";
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)x+=c[i];
	}
	
	for(int i=1;i<=(x.size()-1)/2+1;i++){
		if(x[x.size()-i]!=x[i]){
			x[x.size()-i]=x[i];
			sum++;
		} 
	}
	
	cout<<sum;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
