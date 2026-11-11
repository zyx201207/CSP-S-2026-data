#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ar,ans,l1=1,l2;
long long a[N];
char c[N],cr;
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l2=n+1;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	while(l1<=l2){
		if(f==0){
			if(ar==0){
				ar=a[l1];
				cr=c[l1];
				l2--;
				f=1;
			}
			else{
				if(cr==c[l1]){
					if(ar<a[l1]){
						f=1;
						l2--;
						ar=a[l1]-ar;
					} 
					else{
						ar-=a[l1];
						l1++;
					} 
				}
				else{
					if(ar<a[l1]){
						l2--;
						f=1;
						cr=c[l1];
						ans+=ar;
						ar=a[l1]-ar;
					} 
					else{
						ar-=a[l1];
						ans+=a[l1];
						l1++;
					} 
				}
			}	
		}
		else{
			if(ar==0){
				ar=a[l2];
				cr=c[l2];
				f=0;
				l1++;
			}
			else{
				if(cr==c[l2]){
					if(ar<a[l2]){
						l1++;
						f=0;
						ar=a[l2]-ar;
					} 
					else{
						ar-=a[l2];
						l2--;
					} 
				}
				else{
					if(ar<a[l2]){
						l1++;
						f=0;
						cr=c[l2];
						ans+=ar;
						ar=a[l2]-ar;
					} 
					else{
						ar-=a[l2];
						ans+=a[l2];
						l2--;
					} 
				}
			}	
		}		
	}	
	cout<<ans;	
	return 0;
}
