#include <bits/stdc++.h>
using namespace std;
	
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a1=1,b1=1,b2=0;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=i+1 && a1==1){
			a1=0;			
		}
		if(i>1){
			if(a[i]-a[i-1] != a[1]-a[0] && b1==1){
				b1=0;
			}
		}
	}
//	cout<<"123ryf"<<endl;
	if(a1==1){
		double x=sqrt(2*m+0.25)+0.5;
		if(x >= n){
			cout<<n;
			
		}
		else{
			int j;
			for(j=0;j<=x;j++){
				a1=1;
			}
			cout<<j-1;
		}
		return 0;
		
	}
	if(b1==1){
		long long g = a[1]-a[0];
		double x=(g+2*a[0]+sqrt((2*a[0]-g)*(2*a[0]-g)+8*m*g))/(2*g);
		if(x >= n){
			cout<<n;
		}
		else{
			int j;
			for(j=0;j<=x;j++){
				a1=1;
			}
			cout<<j-1;
		}
		return 0;
	}
		
//	int h = m;
//	if(h/2<n){
//		printf("%.0f\n",h/3);
//		return 0;
//	}
//	if(h/4<n){
//		printf("%.0f\n",h/6);
//		return 0;
//	}
//	if(h/8<n){
//		printf("%.0f\n",h/10);
//		return 0;
//	}
//	printf("%.0f\n",h/27);
	long long mne=1,ue=0;
	sort(a.begin(),a.end(),greater<int>());
//	for(int i=0;i<n;i++){
//		cout<<a[i];
//	}
	for(int i=0;i<n;i++){
		long long mn=1,u=0;
//		cout<<a[i]<<endl;
		for(int j=i+1;j<n ;j++){
//			cout<<"asd"<<endl;
			if(u+a[i]-a[j]<=m){
//				cout<<i<<" "<<a[j]<<endl;
				mn+=1;
				u+=a[i]-a[j];	
			}
			
		}
		mne=max(mne,mn);
		mn=1;
		u=0;
	}
	cout<<mne<<endl;
		
	return 0;
}
