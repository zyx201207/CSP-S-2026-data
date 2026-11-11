#include <bits/stdc++.h>
using namespace std;
long long m;
long long a[500005];

long long sum=0;
bool flag=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin >> n;
	cin >> m;
	if(n>=5000){
		if(n==1){
		cout << 1 ;
		return 0;
	}
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]-a[i-1]!=1){
			flag=false;
		}
	}
	if(n==2){
		if(abs(a[2]-a[1])>m){
			cout << 1 ;
			return 0;
		}
		else{
			cout << 2;
			return 0;
		}
	}
	if(flag){
		int j=1;
		while(sum+j<=m){
			sum+=j;
			++j;
		}
		cout << j;
	}
	else{
		long long cha=a[2]-a[1];
		if(cha>m) {
			cout << 1;
			return 0;
		}
		int j=1;
		
		while(cha*((j+j*j)/2)<=m){
			++j;
		}
		cout << j;
			}
			

	}
	else{
		cin >> a[1];
	for(int i=2;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int maxx=-1;
	for(int i=1;i<=n;i++){
		bool flag=true;
		for(int j=i;j<=n;j++){
			if(!flag)break;
			int sum=0;
			for(int k=i;k<j;k++){
				sum+=a[j]-a[k];
				if(sum>m){
					flag=false;
					break;
					
				}
				
			}
			
			if(flag){
				
				maxx=max(maxx,j-i+1);
			}
			
		}
	}
	cout << maxx;
	}

	return 0;
}
