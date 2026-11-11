#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
bool c[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxa=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b[0]=a[n-1];
	for(int i=1;i<m;i++){
		bool flase=0;
		int jw=0;
		for(int j=0;j<n-1;j++){
			if(!c[i]){
				if(flase){
					if(b[i-1]&a[j]>b[i]){
						b[i]=b[i-1]&a[j];
						jw=j;
					}
					flase=1;
				}
				else{
					b[i]=b[i-1]&a[j];
					jw=j;
				}
			}
		}
		c[jw]=1;
	}
	cout<<b[m-1]<<endl;
	fclose(stdin),fclose(stdout);
	return 0;
}