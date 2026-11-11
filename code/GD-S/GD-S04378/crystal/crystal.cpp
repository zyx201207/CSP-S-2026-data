#include<bits/stdc++.h> 
using namespace std;
	int n,m;
	int sum=0;

	
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int a1[n];
    int a[n];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}int mj=0;
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		int s=0;
		s=s+1;	
		
	for(int j=1;j<=s;j++)
		
			
			if(a[i]<=a[n/2]){
				a[i]++;
			}
			
				
	else if(a[i]==a[n/2]){
			mj++;
		}
			}
	cout<<mj;
		
	
	return 0;
}
