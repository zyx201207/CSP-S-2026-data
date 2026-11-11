#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],ans=0;
bool flag=1;
void solveA(){
	for(int i=1;i<=n;i++){
		if(a[i+1]!=a[i]){
			cout<<i<<' ';
		}
	}
}
void solveall(){
	int en;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1])flag=0;
	}
	if(flag){
		solveA();
	}
	else solveall();
}
