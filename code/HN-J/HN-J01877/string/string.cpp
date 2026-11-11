#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int a[100015], n, d = 0, e, q = 0, z, u, v, t=0;
	char b[100015];
	string c;
	cin >> n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	e=n-1;
	while(e>-1){
		d+=a[e];
		e--;
	}
	for(int i=0;i<n;i++){
		z=a[i];
		while(z>0){
			c[q]=b[i];
			z--;
			q++;
		}
	}
    if(d%2==1){
    	u=d-1;
	}
	u=d/2;
	for(int i=0;i<d;i++){
		if(c[i]==c[d]){
			v=0;
		}
		else{
			t++;
		}
		
	}
	cout << t;
}
