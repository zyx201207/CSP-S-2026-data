#include<bits/stdc++.h>
using namespace std;
stack<int> qrt;
int a[1000005];
int b[1000005];
int n,m;
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(qrt.empty())
		qrt.push(a[i]),b[i]=a[i];
	     else
	     {
	     	for(int i=1;i<=n;i++)
	     	if(qrt.top()!=a[i])
	     	{
	     		qrt.top()=b[i];
	     	    qrt.pop();
			 }
			 else
			 qrt.top();
			 
		 }
	}
	return 0;
}
//7891
// 九鸟~
//写不完了