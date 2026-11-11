#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n;
	cin>>n>>m;
	vector<int>a(n);
	int max=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int mid=n/2,b=a[mid];
	if(a[mid]-a[mid-1]<a[mid+1]-a[mid]){
		while(m>=0&&mid>=1){
			while((a[mid-1]!=a[mid])&&m>=0){
				a[mid-1]++;
				m--;
			}
			mid--;
		}
	}
	if(a[mid]-a[mid-1]>a[mid+1]-a[mid]){
		while(m>=0&&mid<n){
			while((a[mid+1]!=a[mid])&&m>=0){
				a[mid+1]++;
				m--;
			}
			mid++;
		}
	}
	if(a[mid]-a[mid-1]==a[mid+1]-a[mid]){	
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a[i]==b){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
