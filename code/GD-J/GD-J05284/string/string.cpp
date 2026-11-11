#include<bits/stdc++.h>
using namespace std;

int n;string s;
long long ans;
int a[200050];
char c[200050];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int i = 0,j = n-1;
	while(i<=j){
		int ict = a[i],jct = a[j];
		int k = min(ict,jct);
		a[i]-=k,a[j]-=k;
		if(c[i] != c[j]){
			ans += k;
		}
		if(i==j)break;
		if(a[i]==0){
			i++;
		}
		if(a[j]==0){
			j--;
		}
	}
	cout<<ans;
	return 0;
}
