#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 5e5+5;
int a[N],b[N],f,ff;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
		if(a[i]!=a[i-1] && i>=2){
			f=1;
		}
		if(b[i]!=b[i-1] && i>=2){
			ff=1;
		}
	}
	if(f==0){
		cout << 0 ;
		return 0; 
	}
	if(ff==0){
		int sum = 1;
		for(int i=n-1;i>=1;i--){
			int c = a[i+1] - a[i];
			if(m-c>=0){
				a[i]=a[i+1];
				m-=c;
				sum++;
			}
		}
		cout << sum ;
		return 0;
	}
	else{
		int sum = 0;
		int index = n/2+1;
		int ennd=0;
		for(int i=index-1;i>=1;i--){
			int c = a[i+1]-a[i];
			if(m-c>=0){
				a[i]=a[i+1];
				m-=c;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				sum++;
			}
		} 
		cout << sum+1 << endl;
	}
	return 0;
}
