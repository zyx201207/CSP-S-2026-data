#include<bits/stdc++.h>
using namespace std;
int a[200001];
int b[200001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			b[i]=a[i]&a[j];
			s++;
		}
	}
	sort(b,b+s,cmp);
	cout<<b[1];
	return 0;
} 
