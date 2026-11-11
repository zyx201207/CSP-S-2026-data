#include<bits/stdc++.h>
using namespace std;
char a[10000005],b[10000005];
int main(){
	int n;
	cin>>n;
	int s = 0;
	for(int i = 1;i<=n;i++){
		int c;
		char f;
		cin>>c>>f;
		for(int j = 1;j<=c;j++){
			a[s] = char(f);
			s++;
		}
	}
	int sum = 0;
	for(int i = 0;i<s;i++){
		b[i] = a[s-i-1];
		if(a[i]!=b[i]) sum++;
	} 
	cout<<sum/2;
}
