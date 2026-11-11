#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	int m,n;
	int a[100];
	cin>>m>>n;
	for(int i=1;i==m;i++){
		cin>>a[i]; 
	}
	cout<<m<<" "<<n<<" "<<a[1]; 
	fclose("stdin");
	fclose("stdout");
	return 0;
} 
