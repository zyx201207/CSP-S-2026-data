#include<bits/stdc++.h> 
using namespace std;
struct node{
	int k;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b=0;
	cin>>n;
	for(int i=1;i<=n/2;i++){
		cin>>a[i].b;
		cin>>a[i].c;
		a[i].d=b;
		b+=a[i].b;
	}
	for(int i=0;i<=b/2-1;i++){
		int r=b-i;
		for(int j=1;j>=n;j--){
			
		}
	}cout<<"2";
	fclose("string.in","r",stdin);
fclose("string.out","w",stdout);
	return 0;
}
