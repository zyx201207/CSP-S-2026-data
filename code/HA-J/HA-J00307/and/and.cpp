#include<bits/stdc++.h>
using namespace std;
long long n,m,res,lin;
long long a[20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				lin=a[i]&a[j];
				if(lin>res){
					res=lin;
				}
			}
		}
		cout<<res;
		return 0;
	}
	if(m==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int z=j+1;z<n;z++){
					lin=a[i]&a[j]&a[z];
					if(lin>res){
						res=lin;
					}
				}
				
			}
		}
		cout<<res;
		return 0;
	}
	if(m==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int z=j+1;z<n;z++){
					for(int k=z+1;k<n;k++){
						lin=a[i]&a[j]&a[z]&a[k];
						if(lin>res){
							res=lin;
						}
					}
					
				}
				
			}
		}
		cout<<res;
		return 0;
	}
	res=a[n-2]&a[n-3];
	cout<<res;
}

//相同为一 不同为零
