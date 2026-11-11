#include <bits/stdc++.h>
using namespace std;
string q;
int n,r=0,sum,j;
struct p{
	int x;
	char y;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].x;j++){
			q[r]=a[i].y;
			r++;
		}
	}
	j=r;
	for(int i=0;i<r/2;i++){
		if(j<=r/2)break;
		
		if(q[i]==q[j-1]){
			j--;
		}
		
		else{
			sum++;
			j--;	
			} 
		}

	cout<<sum;
	return 0;
}
