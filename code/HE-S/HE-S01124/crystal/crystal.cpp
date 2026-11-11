#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b,k,zmjjkk=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			k++;
		}
		
	}
	b=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]==b){
			zmjjkk++;
		}
	}
//	cout<<b<<" ";
	
	if(k==n){
	int cxy=2,jk=0,kj;
		for(int i=2;jk<m;i++){
			kj=i;
			
			while(kj){
			    kj--;
			    jk++;
			    if(jk==m){
			    	cout<<cxy;
			    	return 0;
				}
			    //cout<<cxy<<" ";
			}
			cxy++;
		}
		//cout<<cxy;
		//return 0;
	}
	if(zmjjkk==n){
		zmjjkk=m/b;
	}
	//cout<<zmjjkk;
	int j=1;
	for(int i=1;i<=zmjjkk;i++){
		
		//cout<<j<<" ";
		if(j+i>=zmjjkk){
			cout<<i;
			return 0;
		}
		j+=i;
	}
	return 0;
} //Oct31==Dec25?
