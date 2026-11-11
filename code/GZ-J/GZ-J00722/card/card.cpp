//GZ-J00722 都匀市第十中学 陈光皓轩 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005];
int main(){
	freopen("card1.in","r",stdin);
	freopen("xx.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
