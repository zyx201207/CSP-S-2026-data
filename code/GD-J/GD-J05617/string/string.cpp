#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long b[n+1],c=0;
	char a[n+1];
	int m=1;
	while(cin>>b[m]>>a[m]){
		if(a[m]==a[m-1]){
			b[m-1]+=b[m];
			b[m]=0;
			a[m]=0;
			m--;
			n--;
		}
		m++;
	}
	a[0]=a[1];
	int j=n;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[j]){
			if(b[i]==b[j]){
				c+=b[j];
				j--;
				n--;
				continue;
			}
			else{
				while(j!=i){
					if(b[i]>b[j]){
						c+=b[j];
						b[i]-=b[j];
						j--;
						n--;
					}
					if(b[i]=b[j]){
						c+=b[j];
						j--;
						n--;
						break;
					}
					if(b[i]<b[j]){
						c+=b[i];
						b[j]-=b[i];
						break;
					}
				}
			}
		}
	}
	cout<<c<<endl;
	return 0;
}
