#include<bits/stdc++.h>
using namespace std;
int n,a[200005],s;
char cc[200005],c[200005];
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>cc[i];
	}
	int t=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c[t]=cc[i];
			//cout<<c[t];
			t++;
		}
	}
	//cout<<endl;
	int e;
	if(t%2==1){
		e=t/2+1;
	}
	else{
		e=t/2;
	}
	for(int i=1;i<=e;i++){
		int q=t-i;
		//cout<<c[i]<<' '<<c[q]<<' '<<q<<endl;
		if(c[i]!=c[q]){
			s++;
		}
	}
	cout<<s;
	return 0;
} 
