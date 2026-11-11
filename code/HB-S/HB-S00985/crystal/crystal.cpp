#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	int n;
	int m;
	cin>>n>>m;
	int x[n+100];
	for(int i=0;i<n;i++){
		cin>>x[i];
		}
	sort(x,x+n);
	x[n]=2e9;
	int yuanx[n+100];
	for(int i=0;i<n;i++){
		yuanx[i]=x[i];
		}
	int yuanm=m;
	int num[n+100]={0};
	for(int i=0;i<n;i++){
		num[i]+=1;
		if(i>0){
		for(int j=i-1;j>=0;j--){
		if(x[j]<=x[i]&&m>=x[i]-x[j]){
			m-=x[i]-x[j];
			num[i]++;
		}
		if(m<x[i]-x[j])
		break;
	}
	}
	m=yuanm;
	for(int k=0;k<=i;k++){
		x[k]=yuanx[k];
		}
}
	sort(num,num+n);
	cout<<num[n-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

	

