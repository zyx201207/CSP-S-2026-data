#include<bits/stdc++.h>
using namespace std;
long long n,aa,s;
long long a[1000005];
char c[1000005],cc[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=aa+1;j<=aa+a[i];j++){
			cc[j]=c[i];
		}
		aa+=a[i];
	}
	if(aa%2==0){
		for(int i=aa/2+1,j=aa/2;i<=n;i++,j--){
			if(cc[i]!=cc[j]){
				s++;
			}
		}
	}
	else{
		for(int i=aa/2+2,j=aa/2;i<=aa;i++,j--){
			if(cc[i]==cc[j])continue;
			s++;
		}
	}
	cout<<s;
	return 0;
}
