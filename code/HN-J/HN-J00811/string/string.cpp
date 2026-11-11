#include<bits/stdc++.h>
using namespace std;
int n,m,lz,ans;
char b[2],a;
string z;

void hwc(){
	int l=0,r=lz-1;
	while(l<r){
		if(z[l]!=z[r])
			ans++;
		l++;
		r--;
	}
	cout<<ans;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d%c%c",&m,&b[0],&b[1]);
		a=b[1];
		for(int j=0;j<m;j++){
			z[lz]=a;
			lz++;
		}
	}
	hwc();
	return 0;
}
