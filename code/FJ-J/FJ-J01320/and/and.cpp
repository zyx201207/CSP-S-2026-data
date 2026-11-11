#include <bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
int n,m;
long long a[N]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cout.tie(0); cin.tie(0);
	cin>>n>>m;
	int mx=-99999;
	if(m==1||m==2){
		for(int i=0;i<n;i++){
			cin>>a[i];	
			if(a[i]>mx) mx=a[i];	
		}
		if(m==1){
			cout<<mx;	
		}else{
			int cnt=0;
			for(int i=0;i<n;i++){	
				if(a[i]==mx) cnt++;	
			}
			if(cnt>=2){
				cout<<mx;
			}else{
				mx=-9999;
				for(int i=0;i<n;i++){
					for(int j=i+1;j>n;j++){
						int num=a[i]&a[j];
						if(num>mx) mx=a[i]&a[j];
					}
				}
			}
		}
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>mx) mx=a[i];			
	}
	if(m==n){
		int num=a[0];
		for(int i=1;i<n;i++){
			num&=a[i];
		}
		cout<<num;
		return 0;
	}
	cout<<mx;
	return 0;
}
