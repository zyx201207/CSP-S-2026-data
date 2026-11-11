//GZ-J00016 遵义市第十九中学 王明杰
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n=0,f=0;
	int a[100000],b[100000];
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c;
		b[i]=c-'0';
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(b[i]==b[j]){
				f=a[j];
				a[i]+=f;
				b[j]=0,a[j]=0;
			}
		}
	}
	sort(a,a+n);
	cout<<a[n-1];
	return 0;
}

