#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[200005];
	char c[200005];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	long long e=0;
	//if(n%2==0) 
	int l=0,r=n-1;
	while(l<r){
		int le=a[l],re=a[r];
		//cout<<le<<" "<<re<<endl;
		if(le>re){
			while(le>re){

				if(c[l]!=c[r]) e+=a[r];
				//cout<<a[r]<<' '<<e<<endl;
				r--;
				
				re+=a[r];
			}
			if(c[l]!=c[r]) e+=a[r];
			//cout<<e<<endl;
			a[r+1]=a[l];
			a[r]=re-le;
			//cout<<a[r];
			if(c[l]!=c[r]) e-=a[r];
			//cout<<a[r];
			c[r+1]=c[l];
			l++;
			//cout<<e<<endl;
		}
		else if(le<re){
			while(le<re){
				//cout<<3<<endl;
				if(c[l]!=c[r]) e+=a[l];
				l++;
				
				le+=a[l];
			}
			if(c[l]!=c[r]) e+=a[l];
			
			a[l-1]=a[r];
			a[l]=le-re;
			if(c[l]!=c[r]) e-=a[l];
			c[l-1]=c[r];
			r--;
		}
		else{
			e+=le;
			c[r]=c[l];
			l++;
			r--;
		}
	}
	cout<<e;
	return 0;
} 
