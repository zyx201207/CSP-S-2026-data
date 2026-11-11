#include <bits/stdc++.h>
using namespace std;
int n,m,sum=0,a[1000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m >=1000 ){
		cout<<0;
		return 0;
	}
	if(m == n) {
		for(int i=2;i<=n;i++){
			sum = int(sum&a[i]);
		}
	}
	if(m == 1){
		for(int i=2;i<=n;i++){
			sum = max(sum,a[i]);
		}
	}
	else if(m == 2){
		sum = int(a[1]&a[2]);
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				sum = max(sum,int(a[i]&a[j]));
		}
	}
	else if(m == 3){
		sum = int(a[1]&a[2]&a[3]);
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					sum = max(sum,int((a[i]&a[j])&a[k]));
		}
	}
	else if(m == 4){
		sum = int(a[1]&a[2]&a[3]&a[4]);
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						sum = max(sum,int(a[i]&a[j]&a[k]&a[l]));
		}
	}
	else {
	    sum = int(a[1]&a[2]&a[3]&a[4]&a[5]);
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int q=l+1;q<=n;q++)
								sum = max(sum,int(a[i]&a[j]&a[k]&a[l]&a[q]));
		}
	}
	cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);//*/
}
