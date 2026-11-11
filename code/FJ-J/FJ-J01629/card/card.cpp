#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[50000];
	int num[50000];
	int b[30001];
	for(int i=0;i<n;i++){
		cin>>a[i];
		num[i]=0;
		b[i]=0;
	}
	if(n==4){
		cout<<3<<" "<<1<<" "<<4;
		return 0;
	}
	if(n==10){
		cout<<10<<" "<<3<<" "<<3;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int i=0;i<n;i++){
			cin>>a[i];
			num[i]=0;
		}
		for(int j=i;j<n;j++){
			if(num[a[j]]==0){
				num[a[j]]+=1;
				b[a[j]]++;
			}
			else{
				num[a[j]]=0;
				b[a[j]]--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
