#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("string.in");
	ofstream out("string.out");
//	
	int n;
	in>>n;
	vector<int> vl(n);
	vector<char> vc(n);
//	cout<<n;
	for(int i=0;i<n;i++){
		in>>vl[i];
		in>>vc[i];
//		cout<<vl[i]<<vc[i]<<endl;
		
	}
long long cnt=0,nll=vl[0],nrl=vl[n-1],l=0,r=n-1;
	char nlc=vc[0],nrc=vc[n-1];
	
	while(l<r){
//		cout<<l<<r;
//		cout<<nlc<<nrc;
//		cout<<nll<<nrl;
//		cout<<endl;
		if(nlc!=nrc){
			cnt+=min(nll,nrl);
		}
			if(nll>nrl){
				nll-=nrl;
				r--;
				if(r<=l) break;
				nrl=vl[r];
				nrc=vc[r];
			}
			
			else if(nll<nrl){
				nrl-=nll;
				l++;
				if(r<=l) break;
				nll=vl[l];
				nlc=vc[l];
			}
			
			else if(nll==nrl){
				r--;
				l++;
				if(r<=l) break;
				nrl=vl[r];
				nrc=vc[r];
				nll=vl[l];
				nlc=vc[l];
			}
//			break;
		}
//		cout<<1;
	out<<cnt;
	return 0;
} 
