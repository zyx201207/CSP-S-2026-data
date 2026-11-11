#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long x1,j1,x2,j2;
	x1=1;
	x2=n;
	j1=0;
	j2=0;
	long long cnt=0; 
	while(x1!=x2){
		if(c[x1]!=c[x2]){
			cnt+=min(a[x1]-j1,a[x2]-j2);
		}
		j1+=min(a[x1]-j1,a[x2]-j2);
		j2+=min(a[x1]-j1,a[x2]-j2);
		if(j1>=a[x1]){
			x1++;
			j1=0;
		}
		if(j2>=a[x2]){
			x2--;
			j2=0;
		}	
	}
	cout<<cnt;
}
