#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<char> str;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[100005],b[100005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	int max=-1;
	int maxi;

	for(int j=0;j<m;j++){
		max=-1;
		for(int i=0;i<n;i++){
		    if(a[i]>=max){
			    max=a[i];
			    maxi=i;
			    
	    	}
	    }
	    a[maxi]=-1;
	}
	cout<<b[maxi];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
