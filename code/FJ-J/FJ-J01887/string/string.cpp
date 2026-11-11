#include <bits/stdc++.h>
using namespace std;

int n,a,sum,t;
string maxs;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		t = c;
		for(int j=1;j<=a;j++){
			maxs += t;
		}
	}
	
	for(int i=0;i<maxs.size()/2;i++){
		if(maxs[i] > maxs[maxs.size()-1-i] || maxs[i] < maxs[maxs.size()-1-i]){
			sum ++;
		}
	}


	cout<<sum;
	return 0;
}
