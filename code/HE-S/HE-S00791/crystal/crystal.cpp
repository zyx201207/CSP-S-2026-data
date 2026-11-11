#include<bits/stdc++.h>
using namespace std;
int n,m,k=0,js=1;
long long a[500005]={0};
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int v=n;
	while(v--){
		if(k==0){
			a[0]++;
			m--;
		}
		if(k==0 && a[0]==a[1] && m>0){
			a[0]++;
			a[1]++;
			m=m-2;
		}
		else{
			for(int j=0;j<k+2;j++){
				a[j]++;
				m--;
			}
			int l=k;
			if(a[l]==a[l+1])k++;
			if(m==0){
				for(int i=1;i<n;i++){
					if(a[i]==a[i+1]){
						js++;
					}
				}
				cout<<js;
				break;
			}
			l++;
		}
	}
	return 0;
}


