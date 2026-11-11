//crystal
#include<bits/stdc++.h>
using namespace std;
long raw[500005];
long energy[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long m;
	cin >> n >> m;
	int t1=0;
	for(int i=0;i<n;i++){
		cin >> raw[i];
		energy[i]=raw[i]-t1;
		t1=raw[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int tmpans=0;
		for(int j=i;j<n;j++){
			
			tmpans=j-i;
			//cout << tmpans<< "? ";
			int cb=tmpans*raw[i];
			//cout << raw[i]<< "! ";
			for(int k=i;k<n;k++){
				cb-=energy[k]*(k-j+1);
			}
			//cout << cb << " ";
			if(cb>m) tmpans=0;
			ans=max(tmpans,ans);
		}
		ans=max(tmpans,ans);
	}
	cout << ans<< endl;
} 
