#include <bits/stdc++.h>
using namespace std;
int a[20005];
char c[20005];
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int i=1;
	int j=n;
	while(true){
		if(c[i]==c[j]){
			int z=abs(a[i]-a[j]);
			a[i]-=z;
			a[j]-=z;
		}else{
			int z=min(a[i],a[j]);
			cnt+=z;
			a[i]-=z;
			a[j]-=z;
		}
		if(a[i]<=0) i++;
		if(a[j]<=0) j--;
		if(i>=j) break;
	}
	cout<<cnt<<endl;
	return 0;
} 
