#include <bits/stdc++.h>
using namespace std;
string hq="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long q;
		char l;
		cin>>q>>l;
		for(long long j=1;j<=q;j++){
			hq+=l;
		}
	}
	long long sum=0;
	for(int i=0;i<=(hq.size()+1)/2-1;i++){
		if(hq[i]!=hq[hq.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
}
