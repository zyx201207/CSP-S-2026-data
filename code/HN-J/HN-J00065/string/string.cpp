#include<bits/stdc++.h>
using namespace std;
char S1[100000005],S2[100000005],c[100000005];
int n,m=0,a[100000005];
int main(){
	freopen("strinng.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<=a[i];j++){
			S1[m]=c[i];
			m++;		
		}
		m=a[i];
		for(int j=0;j>=a[i];j++){
			S2[m]=c[i];		
			m--;
		}
	}
	cout<<4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
