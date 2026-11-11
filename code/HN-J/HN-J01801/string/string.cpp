#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;long long time=0;
	for(int i=0;i<n;i++)
		cin>>a[i]>>c[i];
	for(int x=0,y=n-1;x<y;){
		if(a[x]>a[y]){
			if(c[x]!=c[y])
				time+=a[y];
			a[x]-=a[y];
			y--;
		}else if(a[x]<a[y]){
			if(c[x]!=c[y])
				time+=a[x];
			a[y]-=a[x];
			x++;
		}else{
			if(c[x]!=c[y])
				time+=a[x];
			x++;y--;
		}
	}
	cout<<time;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
