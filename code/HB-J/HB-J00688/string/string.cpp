#include<bits/stdc++.h>
using namespace std;
long long m,n,a;
string c,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			b+=c;
		}
		m+=a;
		//cout<<m<<" "<<b<<" "<<endl;
	}
	a=0;
	for(int i=0;i<m;i++){
		if(b[m-i-1]!=b[i]){
			//cout<<i<<" "<<b[i]<<" "<<m-i-1<<" "<<b[m-i-1]<<endl;
			b[m-i-1]=b[i];
			a++;
			
		}
	}
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
