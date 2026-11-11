#include<bits/stdc++.h> 
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    int a[n+5];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	int max=INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i]and a[m]>max){
				max=a[i] and a[m];
			}
		}
	}
	cout<<max;
	
   return 0;
}
