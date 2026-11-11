#include<bits/stdc++.h>
using namespace std;
const int N=10e5*5+5,M=10e5*3+5;
int a[N],b[M];
int main(){
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int q=i;
		bool p=0;
		for(int j=n-1;j>i;j--){
			for(int z=j-1;z>=i;z--){
				if(a[j]==a[z]){
					q=j;
					p=1;
					break;
				}
			}
			if(p){
				break;
			}
		}
		for(int z=q;z<n;z++){
			b[a[z]]++;
			cout<<z+1<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
