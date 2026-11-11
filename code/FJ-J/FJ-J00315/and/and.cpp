#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+5];
	for(int i=0;i<n;i++){
		cin >> a[i];		
	}
	int e=-1,j=0,an;
	int b[m+5];
	for(int i=0;i<m;i++){
		int b=a[0];
		for(int i=1;i<n;i++){
			if(a[i]>b&&i!=e){
				e=i;
				b[i]=a[i];
				j++; 
				an=a[i];
	        }	
    	}
    }
	for(int i=0;i<m-1;j++){
	    an&=b[i];  	
	}
	cout << b[j];
	return 0;
} 
