#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long b[200000];
	char c[200000];
	for(int i=0;i<n;i++){
		cin>>b[i];
		
		cin>>c[i];
		
	}
	int y=0;
	for(int i=0;i<n;i++){
		y+=b[i];
	}

	char x[200000]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<b[i];j++){
			x[j+i*b[i-1]]=c[i];
		}
	}
	
	char v[200000]={0};
	for(int i=0;i<y;i++){
		v[i]=x[y-1-i];
	}
	bool s=false;
	for(int i=0;i<y;i++){
		if(x[i]!=v[i]){
			s=true;
			break;
		}
		if(i==4){
			cout<<'0';
			return 0;
		}
	}
	char z[200000]={0};
	for(int i=0;i<y/2;i++){
		z[i]=x[i];
	}
	char a[200000]={0};
	for(int i=0;i<y/2;i++){
		a[i]=z[y/2-1-i];
	}
	int w=0;
	for(int i=0;i<y/2;i++){
		if(x[(y%2==0?y/2:y/2+1)+i]!=a[i]){
			x[(y%2==0?y/2:y/2+1)+i]=a[i];
			w++;
		}
	}
	cout<<w;
	return 0;
}
