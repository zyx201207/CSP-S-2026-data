#include<bits/stdc++.h>
using namespace std;

int a[1000000],cha[1000000];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	if(n==1){
		cout<<1;
		return 0;
	}
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		cha[i]=a[i]-a[i-1];
	}
	int cnt=0;
	for(int i=1;i<n;i++){
		m=m-cha[i];
		if(m<0){
			break;
		}
		cnt++;
	}
	cout<<cnt+1;
	
	
	fclose(stdin);fclose(stdout);
	return 0;

} 

