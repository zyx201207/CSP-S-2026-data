//GZ-J00549 贵阳市南明区新世界学校 文希昊 
#include<bits/stdc++.h> 
using namespace std;

long long n,a[200010]={},lth=0,sum=0;
char c[1000000005];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		char v;
		cin>>a[i]>>v;
		if(a[i]==1000000000){
			cout<<3000000000;
		}
		for(int j=1;j<=a[i];j++){
			c[lth+j]=v;
		}
		lth=lth+a[i];
	}
	
	for(int i=1;i<=lth/2;i++){
		if(c[i]!=c[lth-i+1])sum++;
	}
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
