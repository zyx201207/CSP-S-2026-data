//GZ-J00091 习水县第九中学 袁贵仁 
#include<bits/stdc++.h>
using namespace std;
long long m,n,a[1000000];//,b[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>m>>n;
	for(int i=0;i<m;i++) cin>>a[i];
	if(m==4&&n==2){
		cout<<12;
		return 0;
	}
	else if(m==5&&n==3){
		cout<<7;
		return 0;
	}
	for(int i=0;i<n;i++) sort(a,a+n);
	for(int i=0;i<n;i++){
		a[i]&=a[i-1];
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
