#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long mx=-99999;
	vector<int> SlayTheSpire;

	for(int i=0;i<n;i++){
		long long b;
		cin>>b;
		SlayTheSpire.push_back(b);
	}
	for(long long i=0;i<n;i++){
	   if(i+m-1>=n){
			break;
		}
		long long r=SlayTheSpire[i];
		long long cnt=0;
		
			for(long long j=k+1;j<n;j++){
			    if(j+m-2>=n||cnt==m){
			    	break;
		    	}
		    	r=r&SlayTheSpire[j];
		    	cnt++;
		    }
		
			
		if(r>mx){
			mx=r;
		}
	}
		
		
	cout<<mx;
	return 0;
}
