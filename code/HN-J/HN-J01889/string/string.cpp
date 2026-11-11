#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a[200001];
	char b[200001];
	int n;
	long long c=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c+=a[i];
		cin>>b[i];
	}
	int y=0;
	int o=n-1;
	long long f=0;
	for(int i=0;i<n;i++){
		if(y>=o){
			break;
		}
		if(b[y]!=b[o]){
			if(a[y]>a[o]){
				a[y]-=a[o];
				f+=a[o];
				a[o]==0;
				o--;
			}
			else {
				if(a[y]<a[o]){
					a[o]-=a[y];
					f+=a[y];
					a[y]=0;
					y++;
				}
				else{
					f+=a[o];
					a[o]=0;
					a[y]=0;
					o--;
					y++;
				}
			}
		}
		else{
			if(a[y]>a[o]){
				a[y]-=a[o];
				a[o]==0;
				o--;
			}
			else {
				if(a[y]<a[o]){
					a[o]-=a[y];
					a[y]=0;
					y++;
				}
				else{
					a[o]=0;
					a[y]=0;
					o--;
					y++;
				}
			}
		}
	}
	cout<<f;
}
