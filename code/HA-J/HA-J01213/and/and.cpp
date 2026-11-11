#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int temp;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	int num=a[0];
	for(int i=1;i<m;i++){
		num=num&a[i];
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
