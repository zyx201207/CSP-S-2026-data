#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,time=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(a[r]>a[l]){
			if(c[r]!=c[l]){
				time+=a[l];
				//cout<<a[l]<<' '<<a[r]<<"右大不同，加"<<a[l]<<endl;
			}
			
			a[r]-=a[l];
			l++;
		}
		else if(a[r]<a[l]){
			if(c[r]!=c[l]){
				time+=a[r];
				//cout<<a[l]<<' '<<a[r]<<"左大不同，加"<<a[r]<<endl;
			}	
			a[l]-=a[r];
			r--;
		}
		else{
			if(c[r]!=c[l]){
				time+=a[r];
				//cout<<a[l]<<' '<<a[r]<<"具大不同，加"<<a[r]<<endl;
			}
			r--;
			l++;
		}
	}
	cout<<time<<endl;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/


