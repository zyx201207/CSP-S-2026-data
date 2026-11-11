#include <iostream>
#include <bits/stdc++.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	int n,m,ans,ls,num,x,h;
	int a[n],b[n-1];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	ls=b[0];
	for(int i=1;i<n-1;i++){
		if (ls>b[i]){
			ls=b[i];
			num=i;
		}
	}
	ans=1;
	for(int i=0;i<n-num;i++){
		x+=b[num+i];
		h+=x;
		if(h>m){
			break;
		}
		ans++;
	}
	cout<<ans;
	return 0; 
}
