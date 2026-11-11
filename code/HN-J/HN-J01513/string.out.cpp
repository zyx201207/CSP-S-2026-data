#include <iostream>
#include <string>;
using namespace std;
int main(){
	int n,m,O=0,t,q=1;
	cin >> n;
	int a[n+2];
	string b[n+2];
	b[0]='1';
	for (int i=1;i<=n;i++){
		cin >> a[i]>>b[i];
		t+=a[i];
	}
	if (t%2==0)m=t/2;	
	else {
	m=t/2+1;	
	for(int i=1;m<=0;i++){
		m-=a[i];
		q++;
	}
	if(a[q]+m<=0-m)	O+=(a[q]+m);
	else 	O+=(0-m);
		m=t/2+1;
}
	for(int i=1;i<=q;i++){
		for(int j=n;j>q;j--){
			if(a[i]<=0)break;
			if(b[i]==b[j]){
				if(a[i]>=a[j]){
					a[i]-=a[j];
					O +=a[j];
				}else{
					a[i]-=a[j];
					O +=a[i];
				}
			}else {
				if(a[i]>=a[j]){
					a[i]-=a[j];
				}else{
					n--;
					break;
				}				
			}
	}
	}
	cout << O-m;
	return 0;
}
