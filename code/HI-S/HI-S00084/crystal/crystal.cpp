#include <iostream>
using namespace std;
long long n,m,a[5000001],sum=0;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.ans","w",stdout);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int j=2;j<=n-1;j++){
		int mid=max(a[j],max(a[j-1],a[j+1]));
		if(a[j+1]<mid&&(sum+mid-a[j+1])<=m){
			if((mid-a[j+1])>=0){
				sum+=mid-a[j+1];
				a[j+1]+=mid-a[j+1]; 
			}
		}if(a[j]<mid&&(sum+mid-a[j])<=m){
			if((mid-a[j])>=0){
				sum+=mid-a[j];
				a[j]+=mid-a[j];
			} 
		}if(a[j-1]<mid&&(sum+mid-a[j-1])<=m){
			if((mid-a[j-1])>=0){
				sum+=mid-a[j-1];
				a[j-1]+=mid-a[j-1];
			}
		}
	}
	cout << sum-2;
	//fclose(stdin);
	//fclose(stdout); 
	return 0;
}
