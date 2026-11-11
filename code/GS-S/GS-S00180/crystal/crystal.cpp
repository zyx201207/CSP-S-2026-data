#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=0;int m=0;int num=0;
	cin>>n>>m;int a[n];int q=0;int w=0;int e=0;int r=0;
	q=w=e=r=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n);
	int p=n/2;
	for(int j=0;j<n;j++){
		if(q==0)	break;
		if(a[j]<=a[p]){
			num+=1;
			q=q-(a[p]-a[j]); 
			if(a[j+1]==a[p]&&w!=0){
				num+=1;
			}
		}
	}
	cout<<num;
	return 0;
}
