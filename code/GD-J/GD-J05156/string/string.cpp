#include<bits/stdc++.h>
using namespace std;
long long n,s;
struct str{
	long long x;
	char y;
}a[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	} 
	for(int i=1,j=n;i<j;){
		if(a[i].x>a[j].x){
			if(a[i].y!=a[j].y)s+=a[j].x;
			a[i].x-=a[j].x;
			j--;
		}
		else{
			if(a[i].y!=a[j].y)s+=a[i].x;
			a[j].x-=a[i].x;
			i++;
		}
	}
	cout<<s;
	return 0;
}
