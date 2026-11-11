#include<bits/stdc++.h>
using namespace std;
struct node{
	int n,low;
};
bool cmp(node a,node b){
	return a.low>b.low;
}
int n,m;
node a[200010];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].n;
		int p=0;
		while(pow(2,++p)<a[i].n);
		a[i].low=p-1; 
//		cout<<a[i].low<<' ';
	}
	sort(a,a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i].low<<endl;
	}
	return 0;
} 
