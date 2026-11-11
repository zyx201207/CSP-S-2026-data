
#include<iostream>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],r,s=1,sm=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i=0;i<=n-1;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]<a[j]){
				r=a[j];
				a[j]=a[i];
				a[i]=r;
			}
		}
	}
	r=m;
	for(int i=n-1;i>=0;i--){
		for(int j=i-1;j>=0;j--){
			if(a[i]-a[j]>r){
				break;
			}
			s++;
			r-=a[i]-a[j];
		}
		r=m;
		if(s>sm){
			sm=s;
		}
		s=1;
	}
	cout << sm << endl;
	return 0;
}
