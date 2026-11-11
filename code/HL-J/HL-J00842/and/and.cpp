#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b;
	cin >> a>> b;
	long long arr[a];
	for(int i=0;i<a;i++){
		cin >> arr[i];
	}
	long long n[b];
	long long j1;
	for(int i=0;i<b;i++){
		int max=0;
		for(int j=0;j<a;j++){
			if(max<arr[j]){
				max=arr[j];
				j1=j;
			}
		}
		n[i]=max;
		arr[j1]=0;
		cout <<n[i]<<" ";
	}
	int to=n[0];
	for(int i=1;i<a;i++){
		to=to&n[i];
	}
	cout <<to<<endl;
	
	return 0;
}