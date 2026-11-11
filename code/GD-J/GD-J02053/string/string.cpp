#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long cnt=0;
	cin>>n;
	int a[n],x=0,y=n-1;
	char b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++){
		if(b[x]==b[y]){
			if(a[x]>a[y]){
				a[x]-=a[y];
				a[y]=0;
				y--;
			}else if(a[x]<a[y]){
				a[y]-=a[x];
				a[x]=0;
				x++;
			}else{
				a[x]=0;
				a[y]=0;
				x++;
				y--;
			}
		}else{
			if(a[x]>a[y]){
				cnt+=a[y];
				a[x]-=a[y];
				a[y]=0;
				y--;
			}else if(a[x]<a[y]){
				cnt+=a[x];
				a[y]-=a[x];
				a[x]=0;
				x++;
			}else{
				cnt+=a[x];
				a[x]=0;
				a[y]=0;
				x++;
				y--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
