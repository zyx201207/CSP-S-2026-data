//GZ-J00310 遵义市第四中学 张君皓 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int a[100001],n,m=0,i,s=0;
	char b[100001];
	string c;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		m+=a[i];
		for(int j=1;j<=a[i];j++){
			c+=b[i];
		}
	}
	m--;
	i=0;
	while(i<m){
		if(c[i]!=c[m]){
			s++;
		}
		i++;
		m--;
	}
	cout<<s;
	return 0;
}
