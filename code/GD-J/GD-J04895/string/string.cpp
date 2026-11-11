#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[21000];
	double s=0;
	string c[21000];
	cin>>n;
	for(int q=1;q<=n;q++){
		cin>>a[q]>>c[q];
	}
	for(int q=1;q<=1;q++){
		if(c[q]==c[n+1-q]){
			if(!a[q]==a[n+1-q]){
			s+=max(a[q],a[n+1-q])-min(a[q],a[n+1-q]);
			}
		}
		else{
			s+=max(a[q],a[n+1-q]);
		}
	}
	cout<<int(s);
	return 0;
} 
