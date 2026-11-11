#include <bits/stdc++.h>
using namespace std;

const int N=5*1e5+10; 
int n;
long long m;
int a[N];

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int res=0;//使用数量 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int l=a[0],r=a[n-1];
		int mid=(l+r)/2;
//		cout<<mid;
		if(a[i]<mid){
			if(a[i]>=0){
				while(a[i]==mid){
					m--;
					a[i]++;
				}
				a[i]=true;
				res++;
			}
			else if(a[i]<0){
				while(a[i]==mid){
					m--;
					a[i]++;
				}
				a[i]=true;
				res++; 
			}
//			if(a[i]=true){
//				cout<<a[i]<<" ";
//			}
			//res++;
		}

	}
	if(m>=0){
		cout<<res<<endl;
	}
	
	return 0;
} 
