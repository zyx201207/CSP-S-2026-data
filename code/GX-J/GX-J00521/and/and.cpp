#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
int a[1000000];
int Max=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+2005,cmp);
		cout<<a[0];
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int a3=a[i] and a[j];
				cout<<a3<<endl;
				Max=max(Max,a3);
			}
		}
		cout<<Max;
	}else if(m==n){
		for(int i=0;i<n-1;i++){
			int k=a[i];
			k=k and a[i+1];
			cout<<k<<endl;
		}
		cout<<k;
	}else{
		cout<<262142;
	}
	
	return 0;
}
